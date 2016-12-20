//Minimum Path Sum

// Given a m x n grid filled with non-negative numbers, find a path from 
// top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.


//O(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int> > sum(m, vector<int>(n, 0));
        sum[0][0] = grid[0][0];
        for(int i = 1; i < m; i++){
            sum[i][0] = sum[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < n; j++){
            sum[0][j] = sum[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        return sum[m-1][n-1];
    }
};

//As can be seen, each time when we update sum[i][j], we only need sum[i - 1][j] (at the current column) 
//and sum[i][j - 1] (at the left column). So we need not maintain 
//the full m*n matrix. Maintaining two columns is enough and now we have the following code.
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> pre(m, grid[0][0]);
        vector<int> cur(m, 0);
        for (int i = 1; i < m; i++)
            pre[i] = pre[i - 1] + grid[i][0];
        for (int j = 1; j < n; j++) { 
            cur[0] = pre[0] + grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], pre[i]) + grid[i][j];
            swap(pre, cur); 
        }
        return pre[m - 1];
    }
};
