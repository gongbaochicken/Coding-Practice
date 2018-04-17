//Validate Binary Search Tree
/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/


class Solution {
public:
    bool helper(TreeNode* root, TreeNode* left, TreeNode* right){
        //只是比较root level
        if(!root) return true;
        if((left != nullptr && root->val <= left->val) || (right != nullptr && root->val >= right->val)) return false;
        return helper(root->left, left, root) && helper(root->right, root, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};