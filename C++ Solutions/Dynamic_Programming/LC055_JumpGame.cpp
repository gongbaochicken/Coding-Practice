//Jump Game
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false. 
*/

// Solution: Greedy
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0, index = 0;
        const int end = nums.size();
        for (; index < end && index <= maxReach; ++index)
            maxReach = max(maxReach, index + nums[index]);
        //Check if reach the end.
        return index == end;
    }
};