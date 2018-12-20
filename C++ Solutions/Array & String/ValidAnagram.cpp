//Valid Anagram
//Tag: Easy, Map 

/*Question:
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false. 
*/

//Solution in C++:
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> bitMap(26, 0);
        int m = s.size(), n = t.size();
        for(int i = 0; i < m; i++) bitMap[s[i] - 'a']++;
        for(int i = 0; i < n; i++) bitMap[t[i] - 'a']--;
        for(int i = 0; i < bitMap.size(); i++){
            if(bitMap[i] != 0) return false;
        }
        return true;
    }
};