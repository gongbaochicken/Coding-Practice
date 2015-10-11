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
    if(str.size() == 0 || pattern.size() == 0) return false;
    istringstream iss(str);
    string s;
    vector<string> vs;
    while(iss >> s){vs.push_back(s);}
    if (pattern.size() != vs.size()) return false;
    unordered_map<char, string> p2w;
    unordered_map<string, char> w2p;
    for(int i = 0; i < pattern.size(); i++){
      if(p2w.find(pattern[i]) != p2w.end()) {
	if(p2w[pattern[i]] != vs[i]){
	  return false;
	}
      }else{
	if(w2p.find(vs[i]) != w2p.end()){
	  return false;
	}
	w2p[vs[i]] = pattern[i];
	p2w[pattern[i]] = vs[i];
      }
    }
    return true;
  }
};
