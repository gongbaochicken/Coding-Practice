/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
*/

class Solution {
    vector<int> col;
    vector<int> dig45;
    vector<int> dig135;
    vector<string> board;
    set<vector<string>> solution;
public:
    vector<vector<string>> solveNQueens(int n) {
        solution.clear();
        board = vector<string>(n, string(n, '.'));
        
        col = vector<int>(n, 0);
        dig45 = vector<int>(n*2-1, 0);
        dig135 = vector<int>(n*2-1, 0);
        
        nQueen(n, 0);
        return vector<vector<string>>(solution.begin(), solution.end());
    }
    
    bool available(int x, int y, int n) {
        return col[x] == 0 && dig45[x+y] == 0 && dig135[x-y+n-1] == 0;
    }
    
    void updateBoard(int x, int y, int n, int status) {
        col[x] = status;
        dig45[x+y] = status;
        dig135[x-y+n-1] = status;
        board[x][y] = status == 1? 'Q' : '.';
    }

    // try to put queen on yth row
    void nQueen(int n, int y) { 
        if (y == n) {
            solution.insert(board);
            return;
        }
        // try put queen at row y
        for (int x = 0; x < n; ++x) {
            if(!available(x, y, n)) continue;
            updateBoard(x, y, n, 1);
            nQueen(n, y+1);
            updateBoard(x, y, n, 0);
        }
    }
};