//Search a 2D Matrix 
//Tags: Binary Search

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() ==0 || matrix[0].size() == 0) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n -1;
        while(l <= r){
            int mid = (l + r) /2;
            int x = matrix[mid/n][mid%n];
            if(x < target){
                l = mid +1;
            }else if(x > target){
                r = mid -1;
            }else{
                return true;
            }
        }
        return false;
    }
};