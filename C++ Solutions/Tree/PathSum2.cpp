// 113. Path Sum II
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum 
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]


*/

//Classic Solution:
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> curr;
        vector<vector<int>> ans;
        helper(ans, curr, root, sum);
        return ans;
    }
    
    void helper(vector<vector<int>>& ans, vector<int>& curr, TreeNode* root, int target){
        if(root == nullptr) return;
        curr.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == target){
                ans.push_back(curr);
            }
        }
        helper(ans, curr, root->left, target-root->val);
        helper(ans, curr, root->right, target-root->val);
        curr.pop_back();
    }
};
