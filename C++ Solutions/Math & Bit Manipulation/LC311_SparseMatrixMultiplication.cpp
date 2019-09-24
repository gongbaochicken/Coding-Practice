// 311. Sparse Matrix Multiplication
/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]

Output:

     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if (A.size() == 0 || A[0].size() == 0 || B.size() == 0 || B[0].size() == 0) return vector<vector<int>>();
        int m = A.size(), p = A[0].size(), n = B[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < p; ++k) {
                if (A[i][k] != 0) { // key
                    for (int j = 0; j < n; ++j) {
                        ans[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
        }
        return ans;
    }
};