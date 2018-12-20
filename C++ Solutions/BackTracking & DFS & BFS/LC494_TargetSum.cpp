/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. 
For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
*/

//DSF: O(2^N)
class Solution {
public:
    void dfs(vector<int>& nums, int S, int currSum, int& ans, int i) {
        if (i == nums.size()) {
            if (currSum == S) ans++;
            return;
        }
        int num = nums[i];
        int nextSum = currSum+num;
        dfs(nums, S, nextSum, ans, i+1);
        nextSum = currSum-num;
        dfs(nums, S, nextSum, ans, i+1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0;
        int currSum = 0;
        dfs(nums, S, currSum, ans, 0);
        return ans;
    }
};

//DP:The sum of elements in the given array will not exceed 1000.--> bucket[1000]