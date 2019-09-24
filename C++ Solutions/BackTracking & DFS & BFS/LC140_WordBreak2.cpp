/*
Given a non-empty string s and a dictionary wordDict containing a list of 
non-empty words, add spaces in s to construct a sentence where each word 
is a valid dictionary word. Return all such possible sentences.

Note:
    The same word in the dictionary may be reused multiple times in the segmentation.
    You may assume the dictionary does not contain duplicate words.

Example 1:
Input: s = "catsanddog", wordDict = ["cat", "cats", "and", "sand", "dog"]
Output:
[
  "cats and dog",
  "cat sand dog"
]

Example 2:
Input: s = "pineapplepenapple", wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
Explanation: Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog" wordDict = ["cats", "dog", "sand", "and", "cat"]
Output:
*/

// Solution: Top-down DFS + memory
class Solution {
public:
    //Time: T(n) = T(0) + T(1) + … + T(n – 1) = O(2^n), Space: O(2^n)
    unordered_map<string, vector<string>> m;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> wordSet(wordDict.begin(), wordDict.end());
        return helper(wordSet, s);
    }
    
    vector<string> helper(set<string>& wordSet, string& s){
        if(m.find(s) != m.end()) return m[s];
        vector<string> ans;
        if(wordSet.find(s) != wordSet.end()) ans.push_back(s); //base case
        for(int i = 1; i < s.size(); ++i){
            string l = s.substr(0, i), r = s.substr(i);
            if(wordSet.find(l) != wordSet.end()){
                for(string ss: helper(wordSet, r)){
                    ans.push_back(l + " " + ss);
                }
            }
        }
        m[s] = ans;
        return ans;
    }
};