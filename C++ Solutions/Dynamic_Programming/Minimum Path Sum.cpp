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
//the full m*n matrix. Maintaining two columns exchange (prev and curr array can be one actually) is enough
//and now we have the following code.
//
//Another space compression skill is to choose less length side to build the array. The space is O(min(m, n));
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        bool rowMore = grid.size() > grid[0].size();
        int more = rowMore? grid.size(): grid[0].size();
        int less = rowMore? grid[0].size(): grid.size();
        vector<int> arr(less, 0);
        arr[0] = grid[0][0];
        for(int i = 1; i < less; ++i){
            arr[i] = arr[i-1] + (rowMore? grid[0][i] : grid[i][0]);
        }
        for(int i = 1; i < more; ++i){
            arr[0] = arr[0] + (rowMore? grid[i][0]: grid[0][i]);
            for(int j = 1; j < less; ++j){
                arr[j] = min(arr[j-1], arr[j]) + (rowMore? grid[i][j]: grid[j][i]);
            }
        }
        return arr[less-1];
    }
};
