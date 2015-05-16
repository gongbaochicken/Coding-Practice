/* Leetcode: Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to 
adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total 
number of rows in the triangle.
*/

//Solution: Dynamic Programming

class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int row = triangle.size();  
        if(row ==0) return 0;  
        vector<int> minV(triangle[row-1].size());  
        for(int i =row-1; i>=0; i--)  {  
            int col = triangle[i].size();  
            for(int j =0; j<col; j++)  {  
                if(i == row-1)  {  
                    minV[j] = triangle[i][j];  
                    continue;  
                }  
                minV[j] = min(minV[j], minV[j+1]) + triangle[i][j];  
            }  
        }  
        return minV[0];  
    }
};

//Follow up: A little bit slow? is there a better way? 
