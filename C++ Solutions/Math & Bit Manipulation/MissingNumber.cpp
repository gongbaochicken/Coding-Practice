//Missing Number
/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example, Given nums = [0, 1, 3] return 2. 
*/

//Solution:

class Solution {
public:
    //the missing number will occur only once, so the result is the missing number.
    int missingNumber(vector<int>& nums) {
        int i = 0, result = nums.size();
        for(int num : nums){
            result ^= num;
            result ^= i;
            i++;
        }
        return result;
    }
};