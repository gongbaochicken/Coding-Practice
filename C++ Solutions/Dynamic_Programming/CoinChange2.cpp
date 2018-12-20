//518. Coin Change 2

/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.

Note: You can assume that

   0 <= amount <= 5000
   1 <= coin <= 5000
   the number of coins is less than 500
   the answer is guaranteed to fit into signed 32-bit integer

Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:

Input: amount = 10, coins = [10]
Output: 1
 */

//Solution 1:
//Search with memory
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        vector<vector<int>> map(coins.size()+1, vector<int>(amount+1, 0));
        return process(coins, 0, amount, map);
    }

    int process(vector<int>& coins, int index, int target,  vector<vector<int>>& map){
        int res = 0;
        if(index == coins.size()){
            res = target == 0? 1: 0;
            map[index][target] = target == 0? res: -1;
            return res;
        }

        for(int i = 0; coins[index]*i <= target; ++i){
            int mapVal = map[index+1][target-coins[index]*i];
            if(mapVal != 0){
                res += mapVal == -1? 0:mapVal;
            }else{
                res += process(coins, index+1, target - coins[index]*i, map);
            }
        }
        map[index][target] = res;
        return res;
    }
};

//Solution 2:
//Dynamic Programming O(n^3)
//Draw a matrix, coins size * (amount+1)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;
        if(coins.size() == 0) return 0;
        //need to return map[index][amount];
        vector<vector<int>> map(coins.size(), vector<int>(amount+1, 0));
        //left column
        for(int i = 0; i < coins.size(); ++i){
            map[i][0] = 1;
        }
        //top row
        for (int j = 1; coins[0] * j <= amount; j++) {
            map[0][coins[0] * j] = 1;
        }
        //Find the dependence nodes
		for(int i = 1; i < coins.size(); ++i){
		    for(int j = 1; j <= amount; j++){
                if (j - coins[i] >= 0) {
                    map[i][j] = map[i-1][j] + (map[i][j-coins[i]]);
                }else{
                    map[i][j] = map[i-1][j];
                }
		    }
		}
        return map[coins.size()-1][amount];
    }
};
