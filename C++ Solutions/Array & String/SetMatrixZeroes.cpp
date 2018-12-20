//Set Matrix Zeroes 
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

//Solution:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        if(matrix[0].size() == 0) return;
        set<int> row;
        set<int> col;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto item: row){
            for(int x = 0; x < matrix[0].size(); x++){
                matrix[item][x] = 0;
            }
        }
        for(auto item: col){
            for(int y = 0; y < matrix.size(); y++){
                matrix[y][item] = 0;
            }
        }
    }
};