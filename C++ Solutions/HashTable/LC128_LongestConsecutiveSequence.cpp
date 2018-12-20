// 128. Longest Consecutive Sequence
/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
Your algorithm should run in O(n) complexity.

Example:
Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

// Solution: HashMap
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int maxLen = 1;
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums.size(); ++i) {
            if (countMap.find(nums[i]) == countMap.end()) {
                countMap[nums[i]] = 1;
                if (countMap.find(nums[i] - 1 ) != countMap.end()) {
                    maxLen = max(maxLen, merge(nums[i]-1, nums[i], countMap));
                }
                if (countMap.find(nums[i] + 1) != countMap.end())  {
                    maxLen = max(maxLen, merge(nums[i], nums[i]+1, countMap));
                }
            }
        }
        return maxLen;
    }
    
    int merge(int s, int l, unordered_map<int, int>& countMap) {
        int left = s - countMap[s] + 1;
        int right = l + countMap[l] - 1;
        int len = right - left + 1;
        countMap[left] = len;
        countMap[right] = len;
        return len;
    }
};