//Longest Common Prefix
// Time:  O(n * k), k is length of the common prefix
// Space: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        int len = strs[0].size();
        for(auto str: strs){
            for(int i = 0; i < len; i++){
                if(str[i] != strs[0][i]){
                    len = i;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};