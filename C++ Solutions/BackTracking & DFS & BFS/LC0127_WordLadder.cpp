/*
Given two words (beginWord and endWord), and a dictionary's word list, 
find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

//shitting corner case:
// Input:
// "a"
// "c"
// ["a","b","c"]
// Expected:
// 2

// stupid， a->c, there are 2 elements, the lenght is the element number.
// BFS + Hash Set
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;

        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        queue<string> nextLevel;
        dict.erase(beginWord); //tricky: entryword should not be the transformed word, otherwise it's a waste
        nextLevel.push(beginWord);
        int depth = 1;
        while(!nextLevel.empty()) {
            const size_t levelSize = nextLevel.size();
            // avoid count more than once for the same level.
            for (int i = 0; i < levelSize; ++i) {
                string word = nextLevel.front();
                nextLevel.pop();
                dict.erase(word);
                for (int i = 0; i < word.size(); ++i) {
                    char ch = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (word == endWord) return depth;
                        if (dict.find(word) != dict.end()) {
                            dict.erase(word);
                            nextLevel.push(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            ++depth;
        }
        return 0;
    }
};