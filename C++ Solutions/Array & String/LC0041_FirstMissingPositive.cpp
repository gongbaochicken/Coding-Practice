/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
*/

// Space: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        size_t len = nums.size();
        // put values on their right position as possible (nums[i] == nums[nums[i]-1]), otherwise it will detect missing later
        for (size_t i = 0; i < len; ++i) {
            while(nums[i] > 0 && nums[i] <= len && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (size_t i = 0; i < len; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.size() + 1;
    }
};