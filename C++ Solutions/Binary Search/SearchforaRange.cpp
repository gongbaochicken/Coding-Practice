//Search for a Range
//Tags: Binary Search
/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size() == 0) return ans;
        int index = bsf(nums, target);
        int l = index, r = index;
        while(l > 0 && nums[l-1] == nums[l]){l--;}
        while(r < nums.size()-1 && nums[r] == nums[r+1]){r++;}
        ans[0] = l;
        ans[1] = r;
        return ans;
    }

    int bsf(vector<int>& nums, int target){
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return -1;
    }
};

//Time: O(log n)
