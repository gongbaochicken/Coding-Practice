//Pascal's Triangle
/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if(numRows <= 0) return ans;
        ans.push_back(vector<int>(1, 1));
        for(int i = 1; i < numRows; i++){
            vector<int> curr(i+1, 1);
            vector<int>& pre = ans[i-1];
            for(int j = 1; j < i; j++){
                curr[j] = pre[j-1] + pre[j]; 
            }
            ans.push_back(curr);
        }
        return ans;
    }
};