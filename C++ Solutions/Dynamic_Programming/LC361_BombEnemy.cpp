// 361. Bomb Enemy
/*
Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3 
Explanation: For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.
*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int result = 0, rowhits = 0;
        vector<int> colhits(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // if left is wall, then this is new start to bomb the row
                if (!j || grid[i][j-1] == 'W') {
                    rowhits = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; ++k)
                        rowhits += grid[i][k] == 'E';
                }
                // if left is wall, then this is new start to bomb the col
                if (!i || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; ++k)
                        colhits[j] += grid[k][j] == 'E';
                }
                if (grid[i][j] == '0')
                    result = max(result, rowhits + colhits[j]);
            }
        }
        return result;
    }
};