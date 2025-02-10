
Serialization is the process of converting a data structure or object into a sequence of 
bits so that it can be stored in a file or memory buffer, or transmitted across a network 
connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on 
how your serialization/deserialization algorithm should work. You just need to ensure that 
a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Example: 
You may serialize the following tree:

    1
   / \
  2   3
     / \
    4   5

as "[1,2,3,null,null,4,5]"

Clarification: Just the same as how LeetCode OJ serializes a binary tree. 
You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note: Do not use class member/global/static variables to store states. 
Your serialize and deserialize algorithms should be stateless.


//Solution: Recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null!";
        }
        string ans = to_string(root->val) + "!";
        ans += serialize(root->left);
        ans += serialize(root->right);
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        string str;
        queue<string> temp;
        while(getline(ss, str, '!')){
            temp.push(str);
        }
        return deserializerHelper(temp);
    }

private:
    TreeNode* deserializerHelper(queue<string>& temp) {
        string str = temp.front();
        temp.pop();
        if(str == "null"){
            return nullptr;
        }
        int val = stoi(str);
        TreeNode* node = new TreeNode(val);
        if(!temp.empty()) node->left = deserializerHelper(temp);
        if(!temp.empty()) node->right = deserializerHelper(temp);
        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));