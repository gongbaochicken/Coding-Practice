// Given a collection of distinct integers, return all possible permutations.

// Example:

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// Solution: Backtracking, using curr vector push and pop, Time: O(N!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        if(nums.size() == 0) return ans;
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
            }
        }
    }

};