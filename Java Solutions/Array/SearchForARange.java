//Search for a range
/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Subscribe to see which companies asked this question
*/

public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = {-1, -1};
        if(nums.length == 0) return ans;
        int index = binarysearch(nums, target);
        if(index == -1) return ans;
        int l = index, r = index;
        while(r+1 < nums.length && nums[r] == nums[r+1]) r++;
        while(l-1 >= 0 && nums[l] == nums[l-1]) l--;
        ans[0] = l;
        ans[1] = r;
        return ans;
    }
    
    int binarysearch(int[] nums, int target) {
        int l = 0, r = nums.length;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                l++;
            }else{
                r--;
            }
        }
        return -1;
    }
}