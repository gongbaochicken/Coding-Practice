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
    NumArray(vector<int> nums) {
        if (nums.size() == 0) return;
        sum.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            sum.push_back(sum.back() + nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        } else {
            return sum[j] - sum[i-1];
        }
    }
private:
    vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */