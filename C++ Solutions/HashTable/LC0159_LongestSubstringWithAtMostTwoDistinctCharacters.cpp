// 159. Longest Substring with At Most Two Distinct Characters
/*
Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.

Example 1:

Input: "eceba"
Output: 3
Explanation: t is "ece" which its length is 3.
Example 2:

Input: "ccaabbb"
Output: 5
Explanation: t is "aabbb" which its length is 5.
*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char,int> count;
        int j = 0, maxLen = 0; // j is start
        for(int i = 0; i < s.size(); ++i) {
            count[s[i]]++;
            while(count.size() > 2) {
                if(--count[s[j]] == 0)
                    count.erase(s[j]);
                j++;
            }
            maxLen = max(maxLen, i - j + 1);
        }
        return maxLen;
    }
};