/*
Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.
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
 //// DFS: beats 100%
class Solution {
public:
    struct Result {
        TreeNode* node;
        int dist;
        Result(TreeNode* aNode, int aDist): node(aNode), dist(aDist) {}
    };
    
    Result dfs(TreeNode* root) {
        if (root == nullptr) return Result(nullptr, -1);
        Result l = dfs(root->left);
        Result r = dfs(root->right);
        int newDist = max(l.dist, r.dist) + 1;
        TreeNode* ansNode = l.dist == r.dist ? root : l.dist > r.dist ? l.node : r.node;
        return Result(ansNode, newDist);
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).node;
    }
};