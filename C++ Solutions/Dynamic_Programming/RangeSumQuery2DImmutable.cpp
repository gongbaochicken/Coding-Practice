//Range Sum Query 2D - Immutable
/*
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

class NumMatrix {
public:
    //dp[i+1][j+1] represents the sum of area from matrix[0][0] to matrix[i][j]
    int row, col;
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return;
        row = matrix.size(), col = matrix[0].size();
        dp = vector<vector<int> >(row+1, vector<int>(col+1, 0));
        for(int i = 1; i <= row; i++){
            for(int j = 1; j <= col; j++){
                dp[i][j] = matrix[i-1][j-1] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int xMin = min(row1, row2);
        int xMax = max(row1, row2);
        int yMin = min(col1, col2);
        int yMax = max(col1, col2);
        
        return dp[xMax+1][yMax+1] - dp[xMax+1][yMin] - dp[xMin][yMax+1] + dp[xMin][yMin]; //+1 inclusive, without +1 exclusive
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);