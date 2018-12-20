// 543. Diameter of Binary Tree
/*
Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two 
nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree

          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of 
edges between them. 
*/

// DFS
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int globalMax = 0;
        int maxChildPath = DFS(root, globalMax);
        return globalMax;
    }

    int DFS(TreeNode* root, int& globalMax){
      if(!root) return 0;
      int left = 0, right = 0, curr = 0;
      if(root->left) {
        left = DFS(root->left, globalMax) + 1;
        curr += left;
      }
      if(root->right) {
        right = DFS(root->right, globalMax) + 1;
        curr += right;
      }
      globalMax = curr > globalMax? curr: globalMax;
      return max(left, right);
    }
};