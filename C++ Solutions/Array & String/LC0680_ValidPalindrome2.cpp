// Valid Palindrome 2

/*
 Given a non-empty string s, you may delete at most one character. 
 Judge whether you can make it a palindrome.

Example 1:
Input: "aba" Output: True

Example 2:
Input: "abca" Output: True
Explanation: You could delete the character 'c'.

Note:
    The string will only contain lowercase characters a-z. 
    The maximum length of the string is 50000.
*/

//Solution:
//Time: O(N), because subfunction will only executed once or twice, Space: O(1)
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while(start < end){
            if(tolower(s[start]) != tolower(s[end])){
                return isPalindrome(s, start+1, end) || isPalindrome(s, start, end-1);
            }else{
                start++;
                end--;
            }
        }
        return true;
    }
    
    bool isPalindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]--) return false;
            start++;
            end--;
        }
        return true;
    }
};