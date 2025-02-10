//Binary Tree Level Order Traversal
//Tags: Tree, BFS, 
/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]
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


//1. Recursive Solution in C++:
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
    	levelOrderHelper(root, 1, result);
    	return result;
    }

   void levelOrderHelper(TreeNode *root, int depth, vector<vector<int> > &result) {
    	if (root == NULL) return;
    	
    	if (result.size() < depth) {	// add new level in result
    		result.push_back(vector<int>());
    	}
    	result[depth-1].push_back(root->val); //每次路过某层就加一个到这层
    	levelOrderHelper(root->left, depth+1, result);
    	levelOrderHelper(root->right, depth+1, result);
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
    	    result.push_back(level); //The level has reached to the end.
    	    level.clear();
    	    swap(next, curr); //The current level becomes the previous "next" level.
    	}
    	return result;
    }
};

//Time: O(n), Space: O(1)
