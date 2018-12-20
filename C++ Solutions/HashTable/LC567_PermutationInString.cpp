/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. 
In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input:s1 = "ab" s2 = "eidbaooo"
Output:True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False

Note: The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/


// Hashmap + 2 Pointer
// Time: O(n2), Space: O(1) //26 is const
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int len = s1.size();
        vector<int> freq(26, 0);
        for (char c: s1) {
            ++freq[c-'a'];
        }
        vector<int> copy(26, 0);
        int slow = 0;
        for (int fast = 0; fast < s2.size(); ++fast) {
            copy[s2[fast]-'a']++;
            if (fast - slow + 1 > len) {
                copy[s2[slow]-'a']--;
                slow++;
            }
            if (copy == freq) return true;
        }
        return false;
    }
};