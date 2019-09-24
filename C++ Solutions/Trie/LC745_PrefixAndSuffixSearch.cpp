/*
Given many words, words[i] has weight i.

Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix). It will return the word with given prefix 
and suffix with maximum weight. If no word exists, return -1.

Examples:
Input:
WordFilter(["apple"])
WordFilter.f("a", "e") // returns 0
WordFilter.f("b", "") // returns -1

Note:
words has length in range [1, 15000].
For each test case, up to words.length queries WordFilter.f may be made.
words[i] has length in range [1, 10].
prefix, suffix have lengths in range [0, 10].
words[i] and prefix, suffix queries consist of lowercase letters only.
*/

class TrieNode{
public:
    vector<TrieNode*> next;
    vector<int> idx_list;
    TrieNode(){
        next = vector<TrieNode*> (26, NULL);
    }
    
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word, int idx){
        root->idx_list.push_back(idx); // Deal with empty string case
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            if(!cur->next[word[i] - 'a'])
                cur->next[word[i] - 'a'] = new TrieNode();
            cur = cur->next[word[i] - 'a'];
            cur->idx_list.push_back(idx);
        }
    }
    vector<int> find(string word){
        TrieNode* cur = root;
        for(int i = 0; i < word.size(); i++){
            cur = cur->next[word[i] - 'a'];
            if(!cur) return {};
        }
        return cur->idx_list;
    }
private:
    TrieNode* root;
};

class WordFilter {
public:
    WordFilter(vector<string> words) {
        forward = new Trie();
        backward = new Trie();
        for(int i = 0; i < words.size(); i++){
            forward->insert(words[i], i);
            string rword = words[i];
            reverse(rword.begin(), rword.end());
            backward->insert(rword, i);
        }
    }
    
    int f(string prefix, string suffix) {
        vector<int> pre = forward->find(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> post = backward->find(suffix);
        int i = pre.size() - 1;
        int j = post.size() - 1;
        while(i >= 0 && j >= 0){
            if(pre[i] == post[j]) return pre[i];
            else if(pre[i] > post[j]) i--;
            else j--;
        }
        return -1;
    }
private:
    Trie* forward;
    Trie* backward;
};