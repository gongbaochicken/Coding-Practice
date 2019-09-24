// 366. Find Leaves of Binary Tree
/*
Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

Example:
Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]

Explanation:
1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 
2. Now removing the leaf [2] would result in this tree:
          1          
 
3. Now removing the leaf [1] would result in the empty tree:
          []         
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
private:
    int dfs(TreeNode* root, vector<vector<int>>& ans){
      if(!root) return 0;
      int level = max(dfs(root->left, ans), dfs(root->right, ans))+1;
      if(level > ans.size()) ans.push_back(vector<int>());
      ans[level-1].push_back(root->val);
      return level;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        dfs(root, ans);
        return ans;
    }
};