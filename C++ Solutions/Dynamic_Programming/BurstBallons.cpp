
/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it 
represented by array nums. You are asked to burst all the balloons. If the you burst balloon 
i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent 
indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Given [3, 1, 5, 8], Return 167
    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

//Solution: DP, T: O(N^3), S:O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        // Create Coin Vector, with filling pos =1 and pos = n-1
        int n = nums.size()+2;
        vector<int> coins(n);
        coins[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] > 0) coins[i+1] = nums[i];
        }
        coins[n-1] = 1;

        // DP[left][right] means burst ballons insdie (left, right) range, the max value of coins can get collected.
        vector<vector<int>> dp(n, vector<int>(n));
        // left, i, right, so the distance from left to right, should at least be 2.
        for(int dis = 2; dis < n; dis++) {
            for(int left = 0; left + dis < n; left++) {
                int right = left + dis;
                for(int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right], coins[i]*coins[right]*coins[left] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};

//Tips: nums.insert(nums.begin(), 1), nums.insert(nums.end(), 1);