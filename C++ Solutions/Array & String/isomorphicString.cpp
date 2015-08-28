/*Leetcode: Isomorphic Strings
Given two strings s and t (same length), determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same 
character but a character may map to itself.

For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        int a[256] = {0}, b[256] = {0};
        for(int i = 0; i < s.size(); i++){
            if(a[s[i]] > 0 || b[t[i]] > 0){
                if(a[s[i]] == b[t[i]]){
                    continue;
                }else{
                    return false;
                }
            }else{
                a[s[i]] = i+1 ;
                b[t[i]] = i+1;
            }
        }
        return true;
    }
};