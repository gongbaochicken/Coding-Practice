//Binary Tree Level Order Traversal II 
/*Tags: BSF
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

*/

//1. Recursive Solution in C++:
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        traversal(root, 1, ans);
        reverse(ans.begin(), ans.end()); //Add this line
        return ans;
    }
    
    void traversal(TreeNode* root, int depth, vector<vector<int> >& ans){
        if(root == NULL) return;
        
        if(ans.size() < depth){
            ans.push_back(vector<int>());
        }
        ans[depth-1].push_back(root->val);
        traversal(root->left, depth + 1, ans);
        traversal(root->right, depth + 1, ans);
    }
};
//Time: O(n), Space: O(n)


//2. Iterative Solution in C++:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if(root == NULL) return result;
        queue<TreeNode*> curr, next;
        //level saves the element on the current level;
        vector<int> level;
        curr.push(root);
        while(!curr.empty()){
            while(!curr.empty()){
                TreeNode* node = curr.front();
                curr.pop();
                level.push_back(node->val);
                if(node->left) next.push(node->left);
                if(node->right) next.push(node->right);
            }
            result.push_back(level); 
            level.clear();
            swap(next, curr); 
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
//Time: O(n), Space: O(1)
