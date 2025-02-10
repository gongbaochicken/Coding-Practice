/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

// DFS
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> reachPacific(m, vector<bool>(n));
        vector<vector<bool>> reachAtlantic(m, vector<bool>(n));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, reachPacific, INT_MIN, i, 0);
            dfs(matrix, reachAtlantic, INT_MIN, i, n-1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(matrix, reachPacific, INT_MIN, 0, i);
            dfs(matrix, reachAtlantic, INT_MIN, m-1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachPacific[i][j] && reachAtlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& reachRecord, int preHeight, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || reachRecord[i][j] || matrix[i][j] < preHeight)
            return;

        reachRecord[i][j] = true;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto d: dir) {
            int x = i + d[0], y = j + d[1];
            dfs(matrix, reachRecord, matrix[i][j], x, y);
        }
    }
};

// 优化：用一个helper Matrix. 1 代表P， 2代表A
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0) return ans;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            dfs(matrix, visited, 1, INT_MIN, i, 0);
            dfs(matrix, visited, 2, INT_MIN, i, n-1);
        }
        for (int i = 0; i < n; ++i) {
            dfs(matrix, visited, 1, INT_MIN, 0, i);
            dfs(matrix, visited, 2, INT_MIN, m-1, i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (visited[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int type, int preHeight, int i, int j) {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] == 3 || visited[i][j] == type || matrix[i][j] < preHeight)
            return;

        visited[i][j] += type;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        for (auto d: dir) {
            int x = i + d[0], y = j + d[1];
            dfs(matrix, visited, type, matrix[i][j], x, y);
        }
    }
};