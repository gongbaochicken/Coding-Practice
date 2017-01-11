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
            if(i == begin || candidates[i-1] != candidates[i]){
                curr.push_back(candidates[i]);
                backTracking(candidates, curr, ans, target-candidates[i], i+1);
                curr.pop_back();
            }
        }
    }
};
