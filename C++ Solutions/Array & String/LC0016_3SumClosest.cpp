//3Sum Closest
/*
Given an array S of n integers, find three integers in S such that the 
sum is closest to a given number, target. Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 0;
        if(nums.size() < 3) return closest;
        sort(nums.begin(), nums.end());
        closest = INT_MAX/2; //Otherwise (closest-target) will overflow
        for(int i = 0; i < nums.size()-2; ++i){
            while(i > 0 && i < nums.size()-2 && nums[i] == nums[i-1]) i++; //skip
            int j = i+1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return target;
                }else if(sum < target){
                    j++;
                }else{
                    k--;
                }
                closest = abs(sum-target) < abs(closest-target) ? sum : closest;
            }
        }
        return closest;
    }
};
