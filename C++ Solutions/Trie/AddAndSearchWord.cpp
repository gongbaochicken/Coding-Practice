//Add and Search Word
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

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    
    TrieNode(){
        isWord = false;
        memset(children, 0, sizeof(TrieNode*) * 26);
    }
};

class WordDictionary {
private:    
    TrieNode* root;    
    
    bool searchHelper(const char* c, TrieNode* root){
        if (!root) return false;
        if (*c == '\0') return root->isWord;
        if (*c != '.') {
             return searchHelper(c + 1, root->children[*c - 'a']);
        } else {
            for (int i = 0; i < 26; i++) {
                if (searchHelper(c + 1, root->children[i])) return true;
            }
            return false;
        }
    }
    
public:
    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* p = root;
        int index;
        for (char c: word) {
            index = c - 'a';
            if(p->children[index] == NULL){
                p->children[index] = new TrieNode();
            }
            p = p->children[index];
        }
        p->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        //Use c-string style pointer to speed up [std::string::c_str()]
        return searchHelper(word.c_str(), root);
    }
};

