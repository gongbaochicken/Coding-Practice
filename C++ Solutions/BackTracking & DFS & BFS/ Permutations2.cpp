//Permutations 2
/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
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
                //Only skip when deal with one element.
                while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            }
            
        }
    }
};