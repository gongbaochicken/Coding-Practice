/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Input: ["abcd","dcba","lls","s","sssll"]
Output: [[0,1],[1,0],[3,2],[2,4]] 
Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]

Example 2:
Input: ["bat","tab","cat"]
Output: [[0,1],[1,0]] 
Explanation: The palindromes are ["battab","tabbat"]
*/

// Solution: Hashtable 
// Time:O(n* LlogL)
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j <= words[i].length(); j++) {
                // if the last part is palindrome, then check reverse of the previous part
                if(is_palindrome(words[i], j, words[i].size() - 1)) {
                    string prev = words[i].substr(0, j);
                    reverse(prev.begin(), prev.end());
                    if(dict.find(prev) != dict.end() && i != dict[prev]) {
                        result.push_back({i, dict[prev]});
                    }
                }
                // if the previous part is palindrome, then check reverse of the last part
                if(j > 0 && is_palindrome(words[i], 0, j - 1)) {
                    string last = words[i].substr(j);
                    reverse(last.begin(), last.end());
                    if(dict.find(last) != dict.end() && dict[last] != i) {
                        result.push_back({dict[last], i});
                    }
                }
            }
        }
        return result;
    }
    
    bool is_palindrome(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};