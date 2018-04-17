//Binary Tree Paths 
/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

//Solution:
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        helper(root, to_string(root->val), ans);
        return ans;
    }
    
private:
    void helper(TreeNode* root, string x, vector<string>& ans){
        //Find leaf
        if(!root->left && !root->right){
            ans.push_back(x);
            return;
        }
        if(root->left){
            helper(root->left, x + "->" + to_string(root->left->val), ans);
        }
        if(root->right){
            helper(root->right, x + "->" + to_string(root->right->val), ans);
        }
    }
};