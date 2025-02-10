/*
 Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.

Example 1:
Input:
0 0 0
0 1 0
0 0 0

Output:
0 0 0
0 1 0
0 0 0

Example 2:
Input:
0 0 0
0 1 0
1 1 1

Output:
0 0 0
0 1 0
1 2 1

Note:
    The number of elements of the given matrix will not exceed 10,000.
    There are at least one 0 in the given matrix.
    The cells are adjacent in only four directions: up, down, left and right.
*/

// Solution: BFS. Time: O(M*N). Space: O(M*N)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > ans(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        // initialize
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push(make_pair(i, j));
                }else{
                    ans[i][j] = INT_MAX;
                }
            }
        }
        while(!q.empty()) {
            auto pos = q.front();
            q.pop();
            vector<int> dirX = {-1, 0, +1, 0};
            vector<int> dirY = {0, +1, 0, -1};
            for (int i = 0; i < 4; ++i) {
                int nX = pos.first + dirX[i];
                int nY = pos.second + dirY[i];
                if (nX >= 0 && nX < m && nY >= 0 && nY < n && ans[pos.first][pos.second] + 1 < ans[nX][nY]) {
                    // find more short distance
                    ans[nX][nY] = ans[pos.first][pos.second] + 1;
                    q.push(make_pair(nX, nY));
                }
            }
        }
        return ans;
    }
};