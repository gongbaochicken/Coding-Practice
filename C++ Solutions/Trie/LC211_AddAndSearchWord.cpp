// Add and Search Word
/*Tags: Data structure design
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true

Note:
You may assume that all words are consist of lowercase letters a-z. 
*/

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

//Solution:
//Use Trie as wordDictionary
class WordDictionary {
public:
    struct TrieNode {
        bool isWord;
        vector<TrieNode*> next;
        TrieNode(): isWord(false), next(26, nullptr) {}
    };

    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (char c: word) {
            if (p->next[c - 'a'] == nullptr) {
                p->next[c - 'a'] = new TrieNode();
            }
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, 0, root);
    }

private:
    TrieNode* root;
    bool search(const string& word, int start, TrieNode* node) {
        TrieNode* p = node;
        if (p == nullptr) return false;
        for (int i = start; i < word.size() && p; ++i) {
            char c = word[i];
            if (c != '.') {
                p = p->next[c - 'a'];
            } else {
                TrieNode* tmp = p;
                for (int j = 0; j < 26; ++j) {
                    p = tmp->next[j];
                    if (search(word, i+1, p)) {
                        return true;
                    }
                }
            }
        }
        return p && p->isWord;
    }
};