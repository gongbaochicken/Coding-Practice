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

//Recursive solution:
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
        invertTree(root->right);
        invertTree(root->left);
        swap(root->left, root->right);
        return root;
    }
};

//Solution 2:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *node = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(node);
        return root;
    }
};