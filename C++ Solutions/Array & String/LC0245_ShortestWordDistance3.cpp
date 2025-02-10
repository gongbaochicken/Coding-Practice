// 245. Shortest Word Distance III
/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1
Input: word1 = "makes", word2 = "makes"
Output: 3
Note:
You may assume word1 and word2 are both in the list.
*/

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(words.size() == 2) return 1;
        bool same = word1 == word2;
        int index1 = -1, index2 = -1, minDist = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1){
                index1 = i;
                if (same) {
                    swap(index1, index2);
                }
            }else if(words[i] == word2){
                index2 = i;
            }else{
                continue;
            }
            if(index1 != -1 && index2 != -1){
                minDist = min(minDist, abs(index1 - index2));
            }
        }
        return minDist;
    }
};