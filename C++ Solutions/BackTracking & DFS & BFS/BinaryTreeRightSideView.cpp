//Binary Tree Right Side View
//Tags: BFS, Tree
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

You should return [1, 3, 4]. 
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
//BFS
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightNode;
        if (!root) return rightNode;
        rightView(root, rightNode, 0);
    }
private:
    void rightView(TreeNode* node, vector<int>& rightNode, int level) {
        if (!node) return;
        if (level == rightNode.size())
            rightNode.push_back(node -> val);
        rightView(node -> right, rightNode, level + 1);
        //if last statement works, the following statement will not work.
        rightView(node -> left, rightNode, level + 1); 
    }
};