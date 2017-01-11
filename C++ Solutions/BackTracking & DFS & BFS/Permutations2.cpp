//Permutations II 
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:

[
 [1,1,2],
 [1,2,1],
 [2,1,1]
]
 */


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        vector<int> visited(nums.size(), false);
        backTracking(ans, curr, nums, visited);
        return ans;
    }

    void backTracking(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<int>& visited){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i] == false){
                visited[i] = true;
                curr.push_back(nums[i]);
                backTracking(ans, curr, nums, visited);
                curr.pop_back();
                visited[i] = false;
                while(i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
            }
        }
    }
};
