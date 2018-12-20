/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on 
it represented by array nums. You are asked to burst all the balloons. If the you 
burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and right 
then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
    0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:
Input: [3,1,5,8]  Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/

// Solution: DP, Time: O(N^3), Space: O(N^2)
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        int n = nums.size()+2;
        vector<int> coins(n);
        coins[0] = 1;
        coins[n-1] = 1;
        for (int i = 0; i < n-2; ++i) {
            coins[i+1] = nums[i];
        }
        
        // DP[left][right] means burst ballons insdie (left, right) range, the max value of coins can get collected.
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // left, i, right, so the distance from left to right, should at least be 2.
        for (int dist = 2; dist < n; dist++) {
            for(int l = 0; l+dist < n; l++) {
                int r = l+dist;
                for(int i = l+1; i < r; ++i) {
                    dp[l][r] = max(dp[l][r], coins[i]*coins[l]*coins[r]+ dp[l][i]+dp[i][r]);
                }
            }
        }
        return dp[0][n-1];
    }
};