//Longest Palindromic Substring
//Tags: String, DP

/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

//Solution in C++:

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int start = 0, maxLen = 1;
        for(int i = 0; i < s.size();){
            if(s.size() - i <= maxLen/2) break;
            int left = i, right = i;
            //skip the duplicates,because duplicates has no scary effect on our result.
            while(right < s.size()-1 && s[right] == s[right + 1]) ++right; 
            i = right + 1; //Loop moves forward one more. Please think about why.
            while(right < s.size()-1 && left > 0 && s[left - 1] == s[right + 1]) {--left; ++right;}
            int newLen = right - left + 1;
            if(newLen > maxLen){
                maxLen = newLen;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};