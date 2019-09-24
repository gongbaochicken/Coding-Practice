// 290. Word Pattern
/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:
Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:
Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:
Input: pattern = "abba", str = "dog dog dog dog"
Output: false

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

bool wordPattern(string pattern, string str) {
    if(pattern.size() == 0 && str.size() == 0) return true;
    if(pattern.size() == 0 || str.size() == 0) return false;

    istringstream ss(str);
    string token;
    unordered_map<char, string> mp;
    int pos = 0;
    set<string> deduplicate; // avoid multiple tokens have the same key
    while(pos < pattern.size() && std::getline(ss, token, ' ')) {
        char c = pattern[pos];
        if(mp.find(c) == mp.end()){
            if(deduplicate.find(token) != deduplicate.end()) return false;
            mp[c] = token;
            deduplicate.insert(token);
        }else{
            if(mp[c] != token) return false;
        }
        pos++;
    }
    token.clear();
    getline(ss, token, ' ');
    return pos == pattern.size() && token.empty();        
}