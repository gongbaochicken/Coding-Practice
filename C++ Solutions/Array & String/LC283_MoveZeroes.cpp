/*
Given an array nums, write a function to move all 0's to the end of it while maintaining 
the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

// Solution: Time: O(K), K is number of 0. Space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return;
        for(int i = nums.size() -1; i >= 0; i--){
            if(nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);    
            }
        }
        return;
    }
};