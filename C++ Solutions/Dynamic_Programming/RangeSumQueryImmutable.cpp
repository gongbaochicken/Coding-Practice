//Range Sum Query - Immutable
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
public:
    vector<int> cache = {0};
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cache.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return cache[j+1] - cache[i];
    }
};