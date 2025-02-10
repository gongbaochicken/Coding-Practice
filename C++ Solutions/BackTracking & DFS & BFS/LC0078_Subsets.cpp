/* Given a set of distinct integers, nums, return all possible subsets (the power set).
Note: The solution set must not contain duplicate subsets.
Example:
Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>()); // corner case {}
        if(nums.size() == 0) return ans;
        vector<int> curr;
        backTracking(nums, 0, curr, ans);
        return ans;
    }

    void backTracking(vector<int>& nums, int start, vector<int>& curr, vector<vector<int>>& ans){
        for(int i = start; i < nums.size(); ++i){
            curr.push_back(nums[i]);
            ans.push_back(curr);
            backTracking(nums, i+1, curr, ans);
            curr.pop_back();
        }
        return;
    }
};