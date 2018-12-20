/*Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

//Non-Recursive solution: Using stack to ensure that every children of a parent node can be swapped
//Solution 1:
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        stack<TreeNode*> S;
        TreeNode* temp;
        S.push(root);
        while(!S.empty()){
            temp = S.top();
            S.pop();
            swap(temp->left, temp->right);
            if(temp->left) S.push(temp->left);
            if(temp->right) S.push(temp->right);
        }
        return root;
    }
};