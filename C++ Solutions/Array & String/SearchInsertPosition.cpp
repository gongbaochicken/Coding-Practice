//Search Insert Position 
//Tags: Binary Search
/*Given a sorted array and a target value, return the index if the target is found. 
 If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2 ， [1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4 ， [1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n;
        if(nums.size() == 0) return 0;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};