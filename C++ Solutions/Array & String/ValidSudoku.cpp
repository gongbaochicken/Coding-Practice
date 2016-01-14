//Valid Sudoku 
//Tags: HashTable, Math

/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() != 9 || board[0].size() != 9) return false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                for(int k = 0; k < 9; k++){
                    if(i != k && board[k][j] == board[i][j]) return false;
                    if(j != k && board[i][k] == board[i][j]) return false;
                    if(board[i][j] == board[i-i%3 + k/3][j-j%3 + k%3] && i != i-i%3+k/3 && j-j%3+k%3){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};