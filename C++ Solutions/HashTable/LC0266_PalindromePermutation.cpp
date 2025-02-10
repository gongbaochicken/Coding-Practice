// 266. Palindrome Permutation
/*
Given a string, determine if a permutation of the string could form a palindrome.

Example 1:
Input: "code"
Output: false

Example 2:
Input: "aab"
Output: true

Example 3:
Input: "carerac"
Output: true
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if(s.size() <= 1) return true;
        unordered_map<char, int> mp;
        for(char c: s) mp[c]++;
        int count = 0;
        for(auto item: mp){
            if(item.second%2 != 0){
                count++;
            }
        }
        return count <= 1;
    }
};
