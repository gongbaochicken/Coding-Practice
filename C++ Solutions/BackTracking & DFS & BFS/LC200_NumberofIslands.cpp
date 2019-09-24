//Number of Islands
//Tags: DFS, BFS
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000

Answer: 1

Example 2:

11000
11000
00100
00011

Answer: 3
*/

//Solution 1 (DFS):
//Time: O(MN), Space: O(MN)
class Solution {
public:
    int numIslands(vector<vector<char>> &grid){
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
    
private:
    void dfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = '0'; //Note it is char
        if(i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j);
        if(i < grid.size()-1 && grid[i+1][j] == '1') dfs(grid, i+1, j);
        if(j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1);
        if(j < grid[0].size()-1 && grid[i][j+1] == '1') dfs(grid, i, j+1);
    }
};


//Solution 2 (BFS), Time: O(MN), Space: O(min(M, N))
class Solution {
public:
	int numIslands(vector<vector<char>> &grid){
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++ans;
                    BFS(grid, i, j);
                }
            }
        }
        return ans;
    }

private:
    void BFS(vector<vector<char>> &grid, int x, int y){
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        grid[x][y] = '0';

        while(!q.empty()){
            x = q.front().first, y = q.front().second;
            q.pop();

            if(x > 0 && grid[x - 1][y] == '1'){
                q.push(make_pair(x - 1, y));
                grid[x - 1][y] = '0';
            }
            if(x < grid.size() - 1 && grid[x + 1][y] == '1'){
                q.push(make_pair(x + 1, y));
                grid[x + 1][y] = '0';
            }
            if(y > 0 && grid[x][y - 1] == '1'){
                q.push(make_pair(x, y - 1));
                grid[x][y - 1] = '0';
            }
            if(y < grid[0].size() - 1 && grid[x][y + 1] == '1'){
                q.push(make_pair(x, y + 1));
                grid[x][y + 1] = '0';
            }
        }
    }
};