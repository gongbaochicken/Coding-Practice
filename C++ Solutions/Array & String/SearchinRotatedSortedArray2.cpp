//Search in Rotated Sorted Array II 
//Tags: Binary Search
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(nums[mid] == target) return true;
            if(nums[l] < nums[mid]){
                if(nums[l] <= target && target <= nums[mid]){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }else if(nums[l] > nums[mid]){
                if(nums[mid] <= target && target <= nums[r]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }else{
                l++;
            }
        }
        return false;
    }
};