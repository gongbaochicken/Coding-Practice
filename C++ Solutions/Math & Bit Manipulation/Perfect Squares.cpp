//Perfect Squares
/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
*/

class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        for(int i = 0; i <= n; i++){
            dp[i] = i;
            for(int j = 0; j*j <= i; j++){
                dp[i] = min(dp[i-j*j]+1, dp[i]);
            }
        }
        return dp[n];
    }
};