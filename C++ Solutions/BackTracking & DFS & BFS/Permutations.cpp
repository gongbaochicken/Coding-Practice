//Permutations
/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() == 0) return ans;
        vector<int> curr;
        vector<int> visited(nums.size(), false); //very useful to check, to avoid repeated
        backTracking(ans, curr, nums, visited);
        return ans;
    }
    
    void backTracking(vector<vector<int>>& ans, vector<int>& curr, vector<int>& nums, vector<int>& visited){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == false){
                curr.push_back(nums[i]);
                visited[i] = true;
                backTracking(ans, curr, nums, visited);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }
};
     //Time: O(n!)