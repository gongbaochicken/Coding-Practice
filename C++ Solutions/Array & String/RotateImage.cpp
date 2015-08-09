//Rotate Image
//Tags: array
// You are given an n x n 2D matrix representing an image.

// Rotate the image by 90 degrees (clockwise).

// Follow up:
// Could you do this in-place?

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++){
        	for(int j = 0; j < n/2; j++){
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[n-1-j][i];
        		matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
        		matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
        		matrix[j][n-1-i] = temp;
        	}
        }
        if (n % 2 == 1){
            int mid = n / 2;
            for (int i = 0; i < n / 2; i++){
                int tmp = matrix[i][mid];
                matrix[i][mid] = matrix[mid][i];
                matrix[mid][i] = matrix[n - i - 1][mid];
                matrix[n - i - 1][mid] = matrix[mid][n - i - 1];
                matrix[mid][n - i - 1] = tmp;
            }
        }
    }
};

//Time: O(n^2),Space: O(1)


//A much easier idea:
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


//Plus:
/*
 * anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
*/
class Solution {
public:
    void antirotate(vector<vector<int>>& matrix) {
        for(auto x:matrix){ 
            reverse(x.begin(), x.end());
        }
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};


