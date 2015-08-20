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
        int index = binarySearch(nums, target);
        if(index == -1) return ans;
        int l = index, r = index;
        while((l - 1) >= 0 && nums[l] == nums[l-1]) --l;
        while((r + 1) < nums.size() && nums[r] == nums[r+1]) ++r;
        ans[0] = l;
        ans[1] = r;
        return ans;
    }
    
private:
    int binarySearch(vector<int>& nums, int target){
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid +1;
            }else if(nums[mid] > target){
                right = mid -1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

//Time: O(log n)