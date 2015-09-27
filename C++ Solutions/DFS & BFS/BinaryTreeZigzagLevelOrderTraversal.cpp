//Binary Tree Zigzag Level Order Traversal
//Tags: BFS

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

Have you met this question in a real interview? Yes
Example
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7
 

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]
*/

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<int> level;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode *> curr, next;
        curr.push(root);
        int levelNum = 1;
        while(!curr.empty()){
            while(!curr.empty()){
                TreeNode* node = curr.front();
                curr.pop();
                level.push_back(node->val);
                if(node->left != NULL) next.push(node->left);
                if(node->right != NULL) next.push(node->right);
            }
            if(levelNum % 2 == 0){
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            levelNum++;
            level.clear();
            swap(next, curr);
        }
        return ans;
    }
};