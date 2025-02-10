//4 SUM
/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */

//Solution:
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            if(nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            for(int j = i+1; j < nums.size()-2; ++j){
                if(nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if(j-1 > i && nums[j] == nums[j-1]) continue;
                int k = j+1, l = nums.size()-1;
                int need = target - (nums[i]+nums[j]);
                while(k < l){
                    if(nums[k] + nums[l] == need){
                        vector<int> temp{nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        while(k < l && nums[k] == nums[k+1]) k++;
                        while(k < l && nums[l] == nums[l-1]) l--;
                        k++;
                        l--;
                    }else if(nums[k] + nums[l] < need){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
