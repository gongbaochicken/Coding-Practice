//Triangle
/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

//Buttom-up DP, think from right buttom.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> res = triangle.back();
        for (int i = triangle.size()-2; i >= 0; i--) 
            for (unsigned int j = 0; j <= i; j++) 
                res[j] = triangle[i][j] + min(res[j], res[j+1]);
        return res[0];
    }
};