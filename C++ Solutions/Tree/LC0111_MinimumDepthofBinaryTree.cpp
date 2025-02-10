//Minimum Depth of Binary Tree
/*Tags: Tree, BFS,
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

//Solution in C++:
//Recuresion
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        if(root->left && !root->right) return minDepth(root->left)+1;
        if(!root->left && root->right) return minDepth(root->right)+1;
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};

//Time: O(N), Space:O(logN)