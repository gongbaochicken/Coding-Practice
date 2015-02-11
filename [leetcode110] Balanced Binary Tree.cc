

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode *root, int &depth) {
        if (!root) return true;
        int ld, rd;
        ld = rd = 0;
        bool leftBal = isBalanced(root->left, ld);
        bool rightBal = isBalanced(root->right, rd);
        depth = (1 + max(ld, rd));
        return ((abs(ld-rd) < 2) && leftBal && rightBal);
    }
};
