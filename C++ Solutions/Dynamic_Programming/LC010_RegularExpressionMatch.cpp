/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:
s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:
Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".

Example 5:
Input: s = "mississippi", p = "mis*is*p*."
Output: false
*/

// Solution: DP
// Time: O(M*N), Space: O(M*N)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = p.size(), n = s.size(); 
        //Specila Case: "" vs "", "" vs ".*"
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= m; i++){
            if(i >= 2 && p[i-1] == '*'){
                dp[i][0] = dp[i-2][0];
            }
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(s[j-1] == p[i-1] || p[i-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[i-1] == '*' && i >= 2){
                    dp[i][j] = dp[i-2][j];
                    if(p[i-2] == s[j-1] || p[i-2] == '.'){
                        dp[i][j] = dp[i][j] || dp[i][j-1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};