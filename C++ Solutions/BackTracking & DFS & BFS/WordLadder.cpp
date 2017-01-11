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


//Solution in C++:
/*
 Since only one letter can be changed at a time, if we start from "hit", we can only change to those words which have only one different letter
 from it, like "hot". Putting in graph-theoretic terms, we can say that "hot" is a neighbor of "hit".

 The idea is simpy to begin from start, then visit its neighbors, then the non-visited neighbors of its neighbors... Well, this is just the
 typical BFS structure.

 To simplify the problem, we insert end into dict. Once we meet end during the BFS, we know we have found the answer. We maintain a variable dist
 for the current distance of the transformation and update it by dist++ after we finish a round of BFS search (note that it should fit the definition
  of the distance in the problem statement). Also, to avoid visiting a word for more than once, we erase it from dict once it is visited.
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> toVisit;
        findNeighbor(beginWord, wordList, toVisit);
        int dist = 2;
        while(toVisit.size() != 0){
            int len = toVisit.size();
            for(int i = 0; i < len; i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord){
                    return dist;
                }else{
                    findNeighbor(word, wordList, toVisit);
                }
            }
            dist++;
        }
        return 0;
    }

    void findNeighbor(string& word, unordered_set<string>& wordList, queue<string>& toVisit){
        wordList.erase(word);
        for(int i = 0; i < word.size(); ++i){
            char letter = word[i];
            for(int j = 0; j < 26; ++j){
                word[i] = (char) 'a' + j;
                if(wordList.find(word) != wordList.end()){
                    toVisit.push(word);
                    wordList.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};
