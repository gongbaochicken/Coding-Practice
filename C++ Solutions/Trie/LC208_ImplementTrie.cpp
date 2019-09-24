//Implement Trie (Prefix Tree) 
/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/

struct TrieNode {
    bool isWord;
    vector<TrieNode*> nextLevel;
    TrieNode(){
        isWord = false;
        nextLevel.resize(26, nullptr);
    }
    ~TrieNode(){
        for(TrieNode* child: nextLevel){
            delete child;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    ~Trie() {
        delete root;
    }
    
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (p->nextLevel[c - 'a'] == nullptr) {
                p->nextLevel[c - 'a'] = new TrieNode();
            }
            p = p->nextLevel[c - 'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (p->nextLevel[c - 'a'] == nullptr) {
                return false;
            }
            p = p->nextLevel[c - 'a'];
        }
        return p->isWord == true;
    }

    bool startsWith(string prefix) {
        TrieNode* p = root;
        for(int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            if (p->nextLevel[c - 'a'] == nullptr) {
                return false;
            }
            p = p->nextLevel[c - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;    
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");