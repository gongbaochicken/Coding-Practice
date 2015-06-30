/*Unique Paths 1 & 2
Question 1:
A robot is located at the top-left corner of a m x n grid 
(marked 'Start' in the diagram below).

The robot can only move either down or right at any point in 
time. The robot is trying to reach the bottom-right corner of the grid.

How many possible unique paths are there?
*/

Dyanmic Programming
Key: mat[i][j]=mat[i-1][j]+mat[i][j-1]

class Solution {
public:
    int uniquePaths(int m, int n) {
        //int mat[100][100];
        vector<vector<int> > mat(m,vector<int>(n));
        for(int i=0;i<m;i++) {mat[i][0]=1;}
        for(int j=0;j<n;j++) {mat[0][j]=1;}
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                mat[i][j]=mat[i-1][j]+mat[i][j-1];
            }
        }
        return mat[m-1][n-1];
    }
};


/*
Question 2:
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. 
How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively 
in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        const int m=obstacleGrid.size(); 
        const int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0; //First position is obstacle.
        obstacleGrid[0][0]=1;
        for(int i=1;i<m;i++) {
            if(obstacleGrid[i][0]!=1){obstacleGrid[i][0]=obstacleGrid[i-1][0];}
            else{ obstacleGrid[i][0]=0;}
        }
        for(int j=1;j<n;j++) {
            if(obstacleGrid[0][j]!=1){obstacleGrid[0][j]=obstacleGrid[0][j-1];}
            else{ obstacleGrid[0][j]=0;}
        }   
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                obstacleGrid[i][j]=(obstacleGrid[i][j]==1)?0:obstacleGrid[i-1][j]+obstacleGrid[i][j-1];
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};