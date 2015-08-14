Jump Game
//Jump Game II
//Tags: Greedy
/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example: Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps 
to the last index.) 
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxReachPos = nums[0], currReachPos = nums[0], count = 1, n = nums.size();
        for(int i = 1; i <= min(n, maxReachPos); ++i){
        	currReachPos = max(currReachPos, nums[i] + i);
        	if(i == n-1) return count; //reach the end
        	if(i == maxReachPos){ //switch to new reach point, and jump at the same time
        		maxReachPos = currReachPos;
        		count++;
        	}
        }
        return 0;
    }
};