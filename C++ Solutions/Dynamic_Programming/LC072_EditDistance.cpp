//72. Edit Distance

/* Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character*/

//Time: O(M*N), Space: O(M*N)
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        word1 = "0" + word1;
        word2 = "0" + word2;
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1));
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int i = 0; i <= n; i++) dp[0][i] = i;
        for(int i = 1; i <= m; i++){
          for(int j = 1; j <= n; j++){
            dp[i][j] = word1[i] == word2[j]? dp[i-1][j-1]:dp[i-1][j-1]+1;
            dp[i][j] = min(dp[i][j], min(dp[i-1][j]+1,dp[i][j-1]+1));
          }
        }
        return dp[m][n];
    }
};

//Space Optimized?: ===> Space: O(N)
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1 == word2) return 0;
        word1 = "0" + word1;
        word2 = "0" + word2;
        int m = word1.size(), n = word2.size();
        vector<int> curr(m+1);
        for(int i = 0; i <= m; i++) curr[i] = i;
        for(int j = 1; j <= n; j++){
          // init for each column
          int prev = curr[0]; // prev ~= dp[i-1][j¬]
          curr[0] = j;
          for(int i = 1; i <= m; i++){
            int temp = curr[i];
            if (word1[i] == word2[j]) {
              curr[i] = prev;
            } else {
              curr[i] = min(prev+1, min(curr[i]+1, curr[i-1]+1));
            }
            prev = temp;
          }
        }
        return curr[m];
    }
};