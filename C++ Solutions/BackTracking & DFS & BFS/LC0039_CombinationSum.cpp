/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/

// Time: O(N^2), Space: O(Target) //all values is positive, worst case 1+1+1+1...
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        if (candidates.empty()) return ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        backTracking(candidates, ans, curr, 0, target);
        return ans;
    }
    
    void backTracking(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& curr, int start, int target) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = start; i < candidates.size() && candidates[i] <= target; ++i) {
            curr.push_back(candidates[i]);
            backTracking(candidates, ans, curr, i, target-candidates[i]);
            curr.pop_back();
        }
    }
};