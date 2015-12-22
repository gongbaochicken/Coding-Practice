//Combination Sum II
/*Tags: Backtracking
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations i
n C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

//Solution: 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i == start || candidates[i] != candidates[i-1]){
                curr.push_back(candidates[i]);
                backTracking(candidates, target-candidates[i], curr, i+1, ans);
                curr.pop_back();
            }
        }
    }
};