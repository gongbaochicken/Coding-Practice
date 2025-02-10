// 	Spiral Matrix   
/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int top = 0, bottom = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        while(true) {
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            if (++top > bottom) break;
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            if (left > --right) break;
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[bottom][i]);
            }
            if (top > --bottom) break;
            for (int i = bottom; i >= top; --i) {
                ans.push_back(matrix[i][left]);
            }
            if (++left > right) break;
        }
        return ans;
    }
};