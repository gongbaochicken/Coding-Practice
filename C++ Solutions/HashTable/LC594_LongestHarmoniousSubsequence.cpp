/*
We define a harmonious array is an array where the difference between its maximum value 
and its minimum value is exactly 1.

Now, given an integer array, you need to find the length of its longest harmonious 
ubsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            mp[curr]++;
            if (mp.find(curr-1) != mp.end()) {
                ans = max(ans, mp[curr] + mp[curr-1]);
            }
            if (mp.find(curr+1) != mp.end()) {
                ans = max(ans, mp[curr] + mp[curr+1]);
            }
        }
        return ans;
    }
};