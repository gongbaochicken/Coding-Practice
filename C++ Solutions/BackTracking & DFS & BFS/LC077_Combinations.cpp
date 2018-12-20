/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

// Solution: Backtracking
// Time: C(4,2) ~ O(N^(N-k)), Space: 2*O(N^(N-k))
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        if (n < k) {
            return ans;
        }
        vector<int> curr;
        backTracking(ans, curr, 0, k, n);
        return ans;
    }
    
    void backTracking(vector<vector<int>>& ans, vector<int>& curr, int start, int k, int n){
        if (curr.size() == k) {
            return ans.push_back(curr);
        }
        for(int i = start; i < n; ++i) {
            curr.push_back(i+1);
            backTracking(ans, curr, i+1, k, n);
            curr.pop_back();
        }
    }
};