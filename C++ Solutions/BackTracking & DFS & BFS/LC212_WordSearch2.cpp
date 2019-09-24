/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

Example:

Input: 
words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]

Output: ["eat","oath"]
Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

class Solution {
struct TrieNode{
    vector<TrieNode*> next;
    bool isWord;
    TrieNode(): isWord(false), next(26, nullptr){}
    ~TrieNode() {
        for (TrieNode* child: next) {
            if (child) {delete(child);}
        }
    }
}; 
    
class Trie{
public:
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (const string& word: words) {
            insert(word);
        }
    }
    
    ~Trie() {
        delete(root);
    }
    
    void insert(const string& word) {
        if (word.size() == 0) return;
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (curr->next[index] == nullptr) {
                curr->next[index] = new TrieNode();
            }
            curr = curr->next[index];
            if (i+1 == word.size()) curr->isWord = true;
        }
    }

    TrieNode* root;
};
    
public:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, string tempStr, vector<string>& ans) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == ' ') return;
        if (root->next[board[i][j]-'a'] != nullptr) {
            char ch = board[i][j];
            board[i][j] = ' ';
            tempStr += ch;
            root = root->next[ch-'a'];
            if (root->isWord) {
                ans.push_back(tempStr);
                root->isWord = false; //deduplicate
            }
            dfs(board, i+1, j, root, tempStr, ans);
            dfs(board, i-1, j, root, tempStr, ans);
            dfs(board, i, j+1, root, tempStr, ans);
            dfs(board, i, j-1, root, tempStr, ans);
            board[i][j] = ch;
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.size() == 0 || board.size() == 0 || words.size() == 0) return ans;
        Trie* trie = new Trie(words);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, trie->root, "", ans);
            }
        }
        return ans;
    }
};