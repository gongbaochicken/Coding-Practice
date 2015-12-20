//Remove Element
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = std::remove(nums.begin(), nums.end(), val);
        nums.resize(it-nums.begin());
        return nums.size();
    }
};

