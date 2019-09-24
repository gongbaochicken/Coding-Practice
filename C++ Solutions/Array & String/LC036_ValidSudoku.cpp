// 36. Valid Sudoku

/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

bool isValidSudoku(vector<vector<char>>& board) {
    if(board.size() != 9 || board[0].size() != 9) return false;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            if(board[i][j] == '.') continue;
            for(int k = 0; k < 9; ++k){
                if(board[i][j] == board[k][j] && i != k) return false;
                if(board[i][j] == board[i][k] && j != k) return false;
                if(board[i][j] == board[i-i%3+k/3][j-j%3+k%3] && i != i-i%3+k/3 && j != j-j%3+k%3) return false;
            }
        }
    }
    return true;
}