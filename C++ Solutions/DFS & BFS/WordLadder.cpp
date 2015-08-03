//Word Ladder
//Tags: BFS
 /*Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
       wordDict.insert(endWord);
        queue<string> toVisit;
        addNextWords(beginWord, wordDict, toVisit);
        int dist = 2;
        while(!toVisit.empty()){
            int len = toVisit.size();
            for(int i = 0; i < len; i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord){
                    return dist;
                }else{
                    addNextWords(word, wordDict, toVisit);
                }
            }
            dist++;
        }
        return 0;
    }
    
private:
    void addNextWords(string word, unordered_set<string>& wordDict, queue<string>& toVisit) {
        wordDict.erase(word);
        for(int i = 0; i < word.length(); i++){
            char letter = word[i];
            for(int j = 0; j < 26; j++){
                word[i] = 'a' + j;
                if(wordDict.find(word) != wordDict.end()){
                    toVisit.push(word);
                    wordDict.erase(word);
                }
            }
            word[i] = letter;
        }
    } 
};