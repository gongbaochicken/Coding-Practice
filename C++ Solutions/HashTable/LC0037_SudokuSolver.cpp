/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Empty cells are indicated by the character '.'.

Note:

The given board contain only digits 1-9 and the character '.'.
You may assume that the given Sudoku puzzle will have a single unique solution.
The given board size is always 9x9.
*/

// Hashtable
class Solution {
public:
    vector<vector<int>> row, col, box;
    
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<int>>(9, vector<int>(10));
        col = vector<vector<int>>(9, vector<int>(10));
        box = vector<vector<int>>(9, vector<int>(10));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    row[i][n] = 1;
                    col[j][n] = 1;
                    box[(i/3)*3 + j/3][n] = 1;
                }
            }
        }
        fill(board, 0, 0);
    }
    
    bool fill(vector<vector<char>>& board, int x, int y) {
        if (y == 9) return true;
        //next one
        int nx = (x+1)%9;
        int ny = nx == 0 ? y+1: y;
        if (board[y][x] != '.') return fill(board, nx, ny);
        for (int candidate = 1; candidate <= 9; ++candidate) {
            int bx = x/3, by = y/3, b = 3*by + bx;
            if (row[y][candidate] == 0 && col[x][candidate] == 0 && box[b][candidate]==0){
                row[y][candidate] = 1;
                col[x][candidate] = 1;
                box[b][candidate] = 1;
                board[y][x] = candidate + '0';
                if (fill(board, nx, ny)) return true;
                row[y][candidate] = 0;
                col[x][candidate] = 0;
                box[b][candidate] = 0;
                board[y][x] = '.';
            }
        }
        return false;
    }
};