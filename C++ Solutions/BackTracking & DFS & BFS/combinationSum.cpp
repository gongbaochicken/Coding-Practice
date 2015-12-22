//Combination Sum
/*Tags: backtracking
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.
Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 2,3,6,7 and target 7,
A solution set is:
[7] [2, 2, 3]
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
         if(candidates.size() == 0) return ans;
         sort(candidates.begin(), candidates.end());
         vector<int> curr;
         backTracking(candidates, target, curr, 0, ans);
         return ans;
    }
    
    void backTracking(vector<int>& candidates, int target, vector<int> curr, int start, vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        for(int i = start; target >= candidates[i] && i < candidates.size(); i++){
            curr.push_back(candidates[i]);
            backTracking(candidates, target-candidates[i], curr, i, ans);
            curr.pop_back();
        }
    }
};