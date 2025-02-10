/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        m = matrix.size();
        n = matrix[0].size();
        rowSum = matrix;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                rowSum[i][j] = j == 0?  matrix[i][0] : rowSum[i][j-1] + matrix[i][j];
            }
        }
    }
    
    // worst case: O(N)
    void update(int row, int col, int val) {
        if (rowSum.size() == 0 || rowSum[0].size() == 0) return;
        int origValue = col == 0 ? rowSum[row][0] : rowSum[row][col] - rowSum[row][col-1];
        int diff = val - origValue;
        for (int j = col; j < n; j++) {
            rowSum[row][j] += diff;
        }
    }
    
    // worst case: O(M)
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (rowSum.size() == 0 || rowSum[0].size() == 0) return 0;
        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += col1 == 0 ? rowSum[i][col2] : rowSum[i][col2] - rowSum[i][col1-1];
        }
        return ans;
    }

private:
    int m, n;
    vector<vector<int>> rowSum;
};