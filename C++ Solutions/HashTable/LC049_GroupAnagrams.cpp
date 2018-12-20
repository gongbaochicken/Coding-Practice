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