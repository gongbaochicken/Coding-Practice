//Coin Change
/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.
*/


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i){
            for (auto & c : coins){
                if (i - c >= 0 && dp[i - c] != -1){
                    if(dp[i] > 0){
                        dp[i] = min(dp[i], dp[i-c]+1);
                    }else{
                        dp[i] = dp[i-c]+1;
                    }
                }
            }
        }
        return dp[amount];
    }
};