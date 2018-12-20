// Remove Duplicate Letters`
/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"
*/


class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(256, 0);
        vector<bool> visited(256, false);
        for(char c : s){
            count[c]++;
        }
        string ans = " ";
        for(char c : s){
            count[c]--;
            if(visited[c]) continue;
            while(c < ans.back() && count[ans.back()] > 0){
                visited[ans.back()] = false;
                ans.pop_back();
            }
            visited[c] = true;
            ans += c;
        }
        return ans.substr(1);
    }
};