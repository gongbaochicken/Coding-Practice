//Remove Element
/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
*/

//Solution 1: 2 pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if(size == 0) return 0;
        std::sort(nums.begin(), nums.end());
        int i = 0;
        while(i < size && nums[i] != val) i++;
        int j = i;
        while(j < size && nums[j] == val) j++;
        nums.erase(nums.begin()+i, nums.begin()+j);
        return nums.size();
    }
};


//Solution 2:
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto it = std::remove(nums.begin(), nums.end(), val);
        nums.resize(it-nums.begin());
        return nums.size();
    }
};

