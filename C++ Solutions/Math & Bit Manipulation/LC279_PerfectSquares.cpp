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

// More tricky but efficient:
class Solution {
public:
    int numSquares(int n) {
        while (n > 0 && n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;
        for (int a = 0; a*a <= n; ++a) {
            int b = sqrt(n - a*a);
            if (a*a + b*b == n)
                return !!a + !!b;
        }
        return 3;
    }
};