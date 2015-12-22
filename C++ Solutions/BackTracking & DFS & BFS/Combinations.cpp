//Combinations 
/*Tags: DFS
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if(n < k) return ans;
        vector<int> temp;
        backTracking(ans, temp, 0, n, k);
        return ans;
    }
    
    void backTracking(vector<vector<int>>& ans, vector<int>& temp, int start, int n, int k){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = start; i < n; i++){
            temp.push_back(i+1);
            backTracking(ans, temp, i+1, n, k);
            temp.pop_back();
        }
    }
};