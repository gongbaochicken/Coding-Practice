Word Pattern
//Tags: Hash Table
/*
Given a pattern and a string str, find if str follows the same pattern.

  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

  Examples:

  pattern = "abba", str = "dog cat cat dog" should return true.
  pattern = "abba", str = "dog cat cat fish" should return false.
  pattern = "aaaa", str = "dog cat cat dog" should return false.
  pattern = "abba", str = "dog dog dog dog" should return false.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        vector<string> sV;
        unordered_map<char, string> mp;
        set<string> stringSet; 
        istringstream s(str);
        string word;
        while(s >> word){
            sV.push_back(word);
        }
        if(pattern.size() != sV.size()) return false;
        for(int i = 0; i < pattern.size(); i++){
            char c = pattern[i];
            if(mp.find(c) == mp.end()){
                if(stringSet.find(sV[i]) != stringSet.end()) return false;
                stringSet.insert(sV[i]);
                mp[c] = sV[i];
            }else{
                if(mp[c] != sV[i]) return false;
            }
        }
        return true;
    }
};


//Online Reference:
bool wordPattern(string pattern, string str) {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}