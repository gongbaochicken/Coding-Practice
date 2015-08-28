//Valid Sudoku 
//Tags: HashTable, Math

/*Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0) return false;
        for(int i = 0;  i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.'){
                    continue;
                }
                for(int k = 0; k < 9; k++){
                    if(j < k && board[i][k] == board[i][j]) return false;
                    if(i < k && board[k][j] == board[i][j]) return false;
                    if(board[i][j] == board[i - i%3 + k/3][j - j%3 + k%3]){
                        if(i != (i-i%3+k/3) || j != (j-j%3 + k%3)){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};