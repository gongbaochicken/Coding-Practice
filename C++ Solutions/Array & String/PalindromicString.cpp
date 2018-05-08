/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.

Example 1:
Input: "abc" Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa" Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note: The input string length won't exceed 1000.

*/
//Soltuion: Time: O(N^2), Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size();  ++i ) {
            count++;
            // Find the right bound of the middle group, which must be palindrome
            int r = i+1;
            while(r < s.size() && s[r] == s[i]) {
                r++;
                count++;
            }
            // Extend both boundary
            int l = i-1;
            while(l >= 0 && r < s.size() && s[l--] == s[r++]){
                count++;
            }
        }
        return count;
    }
};