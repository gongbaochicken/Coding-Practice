// Given a list of words and two words word1 and word2, return the shortest distance
// between these two words in the list.
//
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.

//Solution: 同向2Pointers, Time: O(N), Space: O(1)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
      if(words.size() == 2) return 1;
      int index1 = -1, index2 = -1;
      int minDist = INT_MAX;
      for(int i = 0; i < words.size(); i++){
        if(words[i] == word1){
          index1 = i;
        }else if(words[i] == word2){
          index2 = i;
        }else{
          continue;
        }
        if(index1 != -1 && index2 != -1){
          minDist = min(minDist, abs(index1 - index2));
        }
      }
      return minDist == INT_MAX? -1: minDist;
    }
};
