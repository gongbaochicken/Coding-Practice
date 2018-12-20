/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up:
This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[l] < nums[mid]){
                if(nums[l] <= target && target <= nums[mid]) r = mid-1;
                else l = mid+1;
            }else if(nums[l] > nums[mid]){
                if(nums[mid] <= target && target <= nums[r]) l = mid+1;
                else r = mid-1;
            }else{
                l++;
            }
        }
        return false;
    }
};