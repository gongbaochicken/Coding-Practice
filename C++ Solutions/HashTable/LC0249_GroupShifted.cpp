// 249. Group Shifted
/*
Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

// Hash-table:
vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;
    for (const auto& word: strings) {
        string token;
        if (word.size() == 1) {
            token = "a";
        } else {
            for (int i = 1; i < word.size(); ++i) {
                int diff = word[i] > word[i-1]? word[i] - word[i-1]: word[i] + 26 - word[i-1];
                token += to_string(diff) + "%";
            }
        }
        mp[token].push_back(word);
    }
    for (auto item: mp) {
        ans.push_back(item.second);
    }
    return ans;
}