/*
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary 
includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may 
still be duplicates.)

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from 
root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left 
boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree 
if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
*/


class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    void addLeaves(TreeNode* root, vector<int>& ans) {
        if (isLeaf(root)) ans.push_back(root->val);

        if (root->left) addLeaves(root->left, ans);
        if (root->right) addLeaves(root->right, ans);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        ans.push_back(root->val);
        if (isLeaf(root)) return ans;

        // left
        TreeNode* p = root->left;
        while(p) {
            if (!isLeaf(p)) {
                ans.push_back(p->val);
            }
            if (p->left) {
                p = p->left;
            } else {
                p = p->right;
            }
        }

        // leaf boundary
        addLeaves(root, ans);

        // right
        stack<int> st;
        p = root->right;
        while(p) {
            if (!isLeaf(p)) {
                st.push(p->val);
            }
            if (p->right) {
                p = p->right;
            } else {
                p = p->left;
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};