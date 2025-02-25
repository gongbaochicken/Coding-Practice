/*49. Group Anagrams
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

// Naive: sort
// Time: O(N * klogk)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            string s1 = s;
            sort(s1.begin(), s1.end());
            mp[s1].push_back(s);
        }
        for(auto pair: mp){
            res.push_back(pair.second);
        }
        return res;
    }
};

// real counting array, using char count distribution to represent keys
// Time: O(N * k)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(const string& s: strs){
            vector<int> count(26);
            for (char c: s) count[c-'a']++;
            string temp;
            for (int i = 0; i < 26; ++i) {
                if (count[i] > 0) {
                    temp += "#";
                    temp += ('a' + i);
                    temp += to_string(count[i]);
                }
            }
            mp[temp].push_back(s);
        }
        vector<vector<string>> res;
        for(auto pair: mp){
            res.push_back(pair.second);
        }
        return res;
    }
};

// another idea: use  multimap<string, string>?