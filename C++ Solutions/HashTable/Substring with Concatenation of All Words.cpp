//Substring with Concatenation of All Words

/*
 You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
*/

//Solution 1:
//Time: O(N*L)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size() == 0 || words.size() == 0 || words[0].size() == 0) return ans;
        int len = words[0].size();
        if(s.size() < len*words.size()) return ans;
        unordered_map<string, int> map;
        for(auto word: words){
            if(map.find(word) != map.end()){
                map[word]++;
            }else{
                map[word] = 1;
            }
        }
        for(int i = 0; i <= s.size() - len * words.size(); i++){
            unordered_map<string, int> copy(map);
            for(int j = 0; j < words.size(); j++) {
                string s2 = s.substr(i+j*len, len);
                if(copy.find(s2) != copy.end()){
                    int count = copy[s2];
                    if(count != 1) copy[s2]--;
                    else copy.erase(s2);
                    if(copy.empty()){
                        ans.push_back(i);
                        break;
                    }
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};


//Solution 2:
//O(KN), K = L[0].length(), N = S.length().
vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> ans;
    int n = S.size(), cnt = L.size();
    if (n <= 0 || cnt <= 0) return ans;

    // init word occurence
    unordered_map<string, int> dict;
    for (int i = 0; i < cnt; ++i) dict[L[i]]++;

    // travel all sub string combinations
    int wl = L[0].size();
    for (int i = 0; i < wl; ++i) {
        int left = i, count = 0;
        unordered_map<string, int> tdict;
        for (int j = i; j <= n - wl; j += wl) {
            string str = S.substr(j, wl);
            // a valid word, accumulate results
            if (dict.count(str)) {
                tdict[str]++;
                count++;
                // a more word, advance the window left side possiablly
                while (tdict[str] > dict[str]) {
                    string str1 = S.substr(left, wl);
                    tdict[str1]--;
                    count--;
                    left += wl;
                }
                // come to a result
                if (count == cnt) 
                    ans.push_back(left);
            }
            // not a valid word, reset all vars
            else {
                tdict.clear();
                count = 0;
                left = j + wl;
            }
        }
    }
    return ans;
}