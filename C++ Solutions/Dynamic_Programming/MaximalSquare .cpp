//Maximal Square 
//Tags: Dynamic Programming

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/

//Solution:
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int> > copy(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                copy[i][j] = matrix[i][j] - '0';
                if(i > 0 && j > 0 && copy[i][j] == 1){
                    copy[i][j] += min(min(copy[i-1][j], copy[i][j-1]), copy[i-1][j-1]);
                }
                maxLen = max(maxLen, copy[i][j]);
            }
        }
        return maxLen * maxLen;
    }
};

//Time:O(m+n), Space: O(m+n)