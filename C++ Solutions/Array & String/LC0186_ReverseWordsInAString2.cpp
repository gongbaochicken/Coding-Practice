// 186. Reverse Words in a String II
/*
Given an input string , reverse the string word by word. 

Example:

Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
Note: 

A word is defined as a sequence of non-space characters.
The input string does not contain leading or trailing spaces.
The words are always separated by a single space.
Follow up: Could you do it in-place without allocating extra space?
*/

class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int n = str.size(), l = 0, r = 0;
        while (r < n) {
            while (r < n && !isspace(str[r])) r++;
            reverse(str.begin() + l, str.begin() + r); 
            l = ++r;
        }
    }
};