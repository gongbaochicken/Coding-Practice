// 471. Encode String with Shortest Length
/*
Given a non-empty string, encode the string such that its encoded length is the shortest.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times.

Note:
k will be a positive integer and encoded string will not be empty or have extra space.
You may assume that the input string contains only lowercase English letters. The string's length is at most 160.
If an encoding process does not make the string shorter, then do not encode it. If there are several solutions, return any of them is fine.
 

Example 1:
Input: "aaa"
Output: "aaa"
Explanation: There is no way to encode it such that it is shorter than the input string, so we do not encode it.
 
Example 2:
Input: "aaaaa"
Output: "5[a]"
Explanation: "5[a]" is shorter than "aaaaa" by 1 character.
*/

class Solution {
private:
    int countRepeat(string& s, string s1) {
        int i = 0, count = 0;
        while(i < s.size()) {
            if (s.substr(i, s1.size()) != s1) break;
            count++;
            i += s1.size();
        }
        return count;
    }

    string dfs(string s, unordered_map<string, string>& mp) {
        if (s.size() < 5) return s;
        if (mp.find(s) != mp.end()) return mp[s];
        string res = s;
        for (int i = 0; i < s.size(); ++i) {
            string str1 = s.substr(0, i+1);
            int K = countRepeat(s, str1);
            string temp;
            for (int k = 1; k <= K; ++k) {
                if (k == 1) temp = str1 + dfs(s.substr(i+1), mp);
                else temp = to_string(k) + "[" + dfs(str1, mp) + "]" + dfs(s.substr(k*str1.size()), mp);
                if (temp.size() < res.size()) res = temp;
            }
        }
        mp[s] = res;
        return res;
    }

public:
    string encode(string s) {
        unordered_map<string, string> mp;
        return dfs(s, mp);
    }
};