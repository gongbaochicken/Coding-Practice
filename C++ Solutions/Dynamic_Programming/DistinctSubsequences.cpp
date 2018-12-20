/*
Given a string S and a string T, count the number of distinct subsequences of S 
which equals T.

A subsequence of a string is a new string which is formed from the original string 
by deleting some (can be none) of the characters without disturbing the relative 
positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while 
"AEC" is not).

Example 1:

Input: S = "rabbbit", T = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
(The caret symbol ^ means the chosen letters)

rabbbit
^^^^ ^^
rabbbit
^^ ^^^^
rabbbit
^^^ ^^^

Example 2:
Input: S = "babgbag", T = "bag"
Output: 5
Explanation:

As shown below, there are 5 ways you can generate "bag" from S.
(The caret symbol ^ means the chosen letters)

babgbag
^^ ^
babgbag
^^    ^
babgbag
^    ^^
babgbag
  ^  ^^
babgbag
    ^^^
*/

//DP: Time: O(MN), Space: O(MN)
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size()+1, vector<int>(s.size()+1, 0));
        //when t is empty, then dp[0][j] = 1
        for(int i = 0; i <= s.size(); ++i) {
            dp[0][i] = 1;
        }

        for(int i = 1; i <= t.size(); ++i) {
            for(int j = 1; j <= s.size(); ++j) {
                //string start from index 0
                if(s[j-1] == t[i-1]) {
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        return dp[t.size()][s.size()];
    }
};