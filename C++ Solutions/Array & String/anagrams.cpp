// Leetcode: Anagrams
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
         vector<string> ret;
         multimap<string, string> S;
         typedef multimap<string, string>::iterator Iterator;
         for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            S.insert(make_pair(tmp, strs[i]));
         }
         for (Iterator it = S.begin(); it != S.end(); it++) {
             if (S.count(it->first) > 1) {
                 pair<Iterator, Iterator> pos = S.equal_range(it->first);
                 while (pos.first != pos.second) {
                     ret.push_back(pos.first->second);
                     pos.first++;
                 }
                 it = pos.second, it--;
             }
         }
         return ret;
    }
};