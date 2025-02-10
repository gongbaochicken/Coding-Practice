//3Sum
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */


//Solution: 2 pointers
//Time: O(n^2)
//Space: O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-2; ++i){
            while(i != 0 && i < nums.size()-2 && nums[i] == nums[i-1]) i++;
            int target = -nums[i];
            int j = i+1, k = nums.size()-1;
            while(j < k){
                if(nums[j] + nums[k] == target){
                    vector<int> temp{nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }else if(nums[j] + nums[k] < target){
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};
