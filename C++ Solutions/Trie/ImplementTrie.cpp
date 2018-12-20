//Implement Trie (Prefix Tree) 
/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
*/

class TrieNode {
public:
    char val;
    TrieNode* children[26];
    bool isWord;
    
    // Initialize your data structure here.
    TrieNode() {
        val = 0;
        memset(children, 0, 26*sizeof(TrieNode*));
        isWord = false;
    }
    
    TrieNode(char c) {
        val = c;
        memset(children, 0, 26*sizeof(TrieNode*));
        isWord = false;
    }
    
    ~TrieNode(){
        for(int i = 0; i < 26; ++i){
            delete children[i];
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* pNode = root;  
        if (word.length() == 0){  
            return;  
        }  
        
        for (int i = 0; i < word.length(); i++){  
            char c = word[i];  
            if (pNode->children[c-'a'] == 0) {  
                TrieNode *pNew = new TrieNode(c);  
                pNode->children[c-'a'] = pNew;  
            }  
            pNode = pNode->children[c-'a'];  
        }  
        pNode->isWord = true;  
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.length() == 0) return false;
        TrieNode* p = root;
        int index;
        for(char c: word){
            index = c - 'a';
            if(p->children[index] == 0){
                return false;
            }
            p = p->children[index];
        }
        return p->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.length() == 0) return false;
        TrieNode* p = root;
        int index;
        for(char c: prefix){
            index = c - 'a';
            if(p->children[index] == 0){
                return false;
            }
            p = p->children[index];
        }
        return true;//Only difference with search()
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");