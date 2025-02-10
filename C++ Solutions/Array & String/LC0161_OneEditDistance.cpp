/*
Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.
*/

class Solution {
public:
    bool isOneReplace(string& s, string& t) {
        int diff = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) {
                if (diff > 0) return false;
                diff = 1;
            }
        }
        return diff == 1;
    }
    
    bool isOneRemove(string& s, string& t) {
        int flag = true;
        int fast = 0;
        for (int slow = 0; slow < t.size(); ++slow) {
            if (s[fast] != t[slow]) {
                if (!flag) return false;
                flag = false;
                // backward one step, because ++slow can make it stay the same position
                --slow;
            }
            ++fast;
        }
        return true;
    }
    
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m == n) {
            return isOneReplace(s, t);
        } else if (m-n == 1) {
            return isOneRemove(s, t);
        } else if (n-m == 1) {
            return isOneRemove(t, s);
        }
        return false;
    }
};