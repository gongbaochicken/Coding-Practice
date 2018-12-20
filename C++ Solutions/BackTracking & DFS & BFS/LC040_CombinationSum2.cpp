/*
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if(candidates.size() == 0) return ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, curr, ans, target, 0);
        return ans;
    }
    
    void backTracking(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans, int target, int begin){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = begin; candidates[i] <= target && i < candidates.size(); ++i){
            if(i + 1 < candidates.size() && candidates[i] != candidates[i+1]){
                curr.push_back(candidates[i]);
                backTracking(candidates, curr, ans, target-candidates[i], i+1);
                curr.pop_back();
            }
        }
    }
};