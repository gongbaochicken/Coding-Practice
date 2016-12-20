//Subsets
/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

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
        if(nums.size() == 0) return ans;
        ans.push_back(vector<int>());
        vector<int> v;
        sort(nums.begin(), nums.end());
        generator(0, v, nums, ans);
        return ans;
    }
    
    void generator(int start, vector<int>& v, vector<int>& nums, vector<vector<int>>& ans){
        if(start == nums.size()) return;
        for(int i = start; i < nums.size(); i++){
            v.push_back(nums[i]);
            ans.push_back(v);
            generator(i+1, v, nums, ans);
            v.pop_back();
        }
    }
};