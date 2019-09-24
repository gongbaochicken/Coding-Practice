// 648. Replace Words
/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor.
For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it.
If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
 
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
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

class Solution {
public:
    void replace(TrieNode* root, string & str) {
        TrieNode* p = root;
        for (int i = 0; i < str.size(); ++i) {
            char c = str[i];
            if (p->nextLevel[c - 'a'] == nullptr) return;
            p = p->nextLevel[c - 'a'];
            if (p->isWord) {
                str.resize(i+1);
                return;
            }
        }
    }

    string replaceWords(vector<string>& dict, string sentence) {
        if (dict.size() == 0 || sentence.size() == 0) return "";
        
        // build trie tree
        TrieNode* root = new TrieNode();
        for (const auto& word: dict) {
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
        
        // search and replace
        stringstream ss(sentence);
        string str, ans;
        while (ss >> str) {
            replace(root, str);
            ans += str + " ";
        }
        ans.pop_back();
        return ans;
    }
};