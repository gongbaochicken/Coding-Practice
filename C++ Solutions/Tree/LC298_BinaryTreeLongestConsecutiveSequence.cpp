// 298. Binary Tree Longest Consecutive Sequence
/*
Given a binary tree, find the length of the longest consecutive sequence path.

The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).

Example 1:

Input:

   1
    \
     3
    / \
   2   4
        \
         5

Output: 3
Explanation: Longest consecutive sequence path is 3-4-5, so return 3.

Example 2:
Input:

   2
    \
     3
    / 
   2    
  / 
 1

Output: 2 

Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
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
public:
    int longestConsecutive(TreeNode* root) {
        int globalMax = 0;
        int roolVal = helper(root, globalMax);
        return globalMax;
    }
    
    int helper(TreeNode* root, int& globalMax){
        if (root == nullptr) return 0;
        int left = helper(root->left, globalMax) + 1;
        int right = helper(root->right, globalMax) + 1;
        if (root->left != nullptr && root->val + 1 != root->left->val) {
            left = 1;
        }
        if (root->right != nullptr && root->val + 1 != root->right->val) {
            right = 1;
        }
        int ans = max(left, right);
        globalMax = max(globalMax, ans);
        return ans;
    }
};