/*
You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
*/

// BFS, Time(MN), Space: Worst case: O(MN)
void wallsAndGates(vector<vector<int>>& rooms) {
    if (rooms.size() == 0) return;
    int m = rooms.size(), n = rooms[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // if it's gate, then push to queue as start point
            if (rooms[i][j] == 0) q.push({i, j});
        }
    }
    vector<vector<int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first, y = p.second;
        for (auto delta: dir){
            int dx = x + delta[0], dy = y + delta[1];
            // only change INF point, once not INF, meaning it has been visited from nearest point already
            if (dx >= 0 && dx < m && dy >= 0 && dy < n && rooms[dx][dy] == INT_MAX) {
                rooms[dx][dy] = rooms[x][y] + 1;
                q.push({dx, dy});
            }
        }
    }
}