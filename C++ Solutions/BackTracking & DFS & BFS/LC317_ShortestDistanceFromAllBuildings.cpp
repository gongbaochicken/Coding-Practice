
// 317. Shortest Distance from All Buildings
/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. 
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/

// Solution:
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return -1;
        const int m = grid.size(), n = grid[0].size();
        vector<vector<int> > distance(m, vector<int>(n, 0)); //distance[i][j] reaching all builds total distance
        vector<vector<int>> reach(m, vector<int>(n, 0)); // how many build it can reach
        int building = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==1) {
                    BFS(grid, i, j, distance, reach);
                    building++; 
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && reach[i][j] == building) {
                    res = min(res, distance[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    
    void BFS(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& distance,vector<vector<int>>& reach) {
        int dist = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> curLevel, nextLevel;
        curLevel.push({i, j});
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!curLevel.empty()) {
            ++dist;
            while (!curLevel.empty()) {
                int x = curLevel.front().first, y =  curLevel.front().second;
                curLevel.pop();
                for (auto d: dir) {
                    int dx = x + d.first, dy = y + d.second;
                    if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && !visited[dx][dy]) {
                        if(grid[dx][dy]==1 || grid[dx][dy]==2) continue;
                        distance[dx][dy] += dist;
                        nextLevel.push({dx, dy});
                        visited[dx][dy] = true;
                        ++reach[dx][dy];
                    }
                }
            }
            swap(curLevel, nextLevel);
        }
        return;
    }
};
