//Alien Dictionary
/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Example 1:
Input: ["wrt", "wrf", "er", "ett", "rftt"]
Output: "wertf"

Example 2:
Input: ["z","x"]
Output: "zx"

Example 3:
Input: ["z", "x", "z"] 
Output: "" 

Note:
    You may assume all letters are in lowercase.
    You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
    If the order is invalid, return an empty string.
    There may be multiple valid order of letters, return any one of them is fine.
*/

//Solution: Topological Sort, Time: O(M*N), Space:O(1)
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";
        vector<int> degree(26, 0); //space: O(1)
        int lenCount = 0;

        // Count length of anwser and init degree
        for (auto word: words) {
          for(auto ch: word) {
            if(degree[ch-'a'] == 0) {
              lenCount++;
              degree[ch-'a'] = 1;
            }
          }
        }

        // Build graph, degree with 1 is the start
        unordered_map<char, set<char>> record; //space: O(1), worse case is 26*26, which is const
        for(int i = 0; i < words.size()-1; ++i) {
          string curr = words[i], next = words[i+1];
          int compLen = min(curr.length(), next.length());
          for(int j = 0; j < compLen; ++j) {
            if(curr[j] != next[j]) {
              if(record[curr[j]].find(next[j]) == record[curr[j]].end()) {
                record[curr[j]].insert(next[j]);
                degree[next[j]-'a']++;
              }
              break; //no need to compare
            }
          }
        }

        // BFS
        string ans;
        queue<char> q;
        for(int i = 0; i < 26; i++) {
          if(degree[i] == 1) q.push(i+'a');
        }
        while(!q.empty()){
          char ch = q.front();
          q.pop();
          ans += ch;
          if(record.find(ch) != record.end()){
            for(char nextCh: record[ch]){
              degree[nextCh-'a']--;
              if(degree[nextCh-'a'] == 1) q.push(nextCh);
            }
          }
        }
        // Avoid case Example 3 
        if (lenCount != ans.size())  return "";
        return ans;
    }
};