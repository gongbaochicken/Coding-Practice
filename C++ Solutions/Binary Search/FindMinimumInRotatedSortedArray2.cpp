//Find Minimum in Rotated Sorted Array II
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// The array may contain duplicates.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, last = nums.size() - 1;
        while(start < last){
            if(nums[start] < nums[last]) break;
            int mid = (start + last) / 2;
            if(nums[mid] > nums[last]){
                start = mid + 1;
            }else if(nums[mid] < nums[last]){
                last = mid;
            }else{
                --last;    //think why cannot "mid++"
                ++start;
             }
        }
        return nums[start];
    }
};
