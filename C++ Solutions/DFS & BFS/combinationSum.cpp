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
        vector<vector<int> > ans;
        vector<int> combination;
        
        if(candidates.size() == 0) return ans;
        sort(candidates.begin(),candidates.end());
        combinationGenerator(candidates, target, ans, combination, 0);
        return ans;
    }
    
    void combinationGenerator(vector<int>& candidates, int target, vector<vector<int> >& ans, vector<int>& combination, int begin){
        if (target == 0) {
            ans.push_back(combination);
            return;
        }
        for (int i = begin; candidates[i] <= target && i != candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            combinationGenerator(candidates, target-candidates[i], ans, combination, i);
            combination.pop_back();
        }
    }
};