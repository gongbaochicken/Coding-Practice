/* 
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.

Example:
Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:
You can assume that you can always reach the last index.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int maxReachPos = nums[0], currReachPos = nums[0], count = 1;
        int endPos = nums.size();
        for (int i = 1; i < endPos && i <= maxReachPos; ++i) {
            currReachPos = max(currReachPos, nums[i]+i);
            if (i == endPos-1) return count;
            // switch to new reach point, which worth 1 jump 
            if (i == maxReachPos) {
                maxReachPos = currReachPos;
                count++;
            }
        }
        return 0;
    }
};