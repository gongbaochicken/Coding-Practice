// 516. Longest Palindromic Subsequence
/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "bbbab"
Output: 4
One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: "cbbd"
Output: 2
One possible longest palindromic subsequence is "bb".
*/

int longestPalindromeSubseq(string s) {
    int m = s.size();
    vector<vector<int>> dp(m, vector<int>(m));
    // because dp[0][m-1] should be the last one to fill
    for (int i = m-1; i >=0; --i) {
        dp[i][i] = 1;
        for (int j = i+1; j < m; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return dp[0][m-1];
}
