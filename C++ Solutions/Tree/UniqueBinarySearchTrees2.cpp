 //Unique Binary Search Trees II
//Tags: DP
/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/


class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }

    vector<TreeNode*> helper(int l, int r) {
        if (l > r) {
             return vector<TreeNode*>(1, NULL);
        }
        vector<TreeNode*> result;
        for (int i = l; i <= r; ++i) {
            vector<TreeNode*> left, right;
            //suppose i is "middle" point
            left = helper(l, i - 1);
            right = helper(i + 1, r);
            for (int j = 0; j < left.size(); ++j) {
                for (int k = 0; k < right.size(); ++k) {                        
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};