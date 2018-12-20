//Construct Binary Tree from Inorder and Postorder Traversal
/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree. 
*/

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
private:
    //mark = position of root in postorder
    TreeNode* makeTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd) { 
        if(postStart >postEnd) return NULL;
        int root = postorder[postEnd];
        int pos = 0;
        for(int i = 0; i < inorder.size(); i++){
            if(inorder[i] == root) {
                pos = i;
                break;
            }
        }
        TreeNode* node = new TreeNode(root);
        node->left = makeTree(postorder, postStart, postStart + (pos - inStart) - 1,  inorder, inStart, pos-1);
        node->right = makeTree(postorder, postStart + (pos-inStart), postEnd-1, inorder,  pos+1, inEnd);
        return node;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return makeTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
