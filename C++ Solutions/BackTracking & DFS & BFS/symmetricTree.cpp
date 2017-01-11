/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 */


//Solution:
//
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return symmetricHelper(root->left, root->right);
    }

    bool symmetricHelper(TreeNode* left, TreeNode* right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val == right->val){
            return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
        }else{
            return false;
        }
    }
};
