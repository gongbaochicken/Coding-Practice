// 99. Recover Binary Search Tree
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:
Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:
Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

Follow up:
A solution using O(n) space is pretty straight forward.
Could you devise a constant space solution?
*/

// Solution 1: Naive Brute Force
// Inorder traversal and put results into vector
// Sort vector
// reconstruct the vector into BST
// Time: O(NlogN), Space:(O(N))


// Solution 2:
// Inorder traversal and check values on fly.
// There 2 cases: the 2 nodes are adjacent or not adjacent.
// case one: 1, 2, 4, 5, 9(first), 8(mid), 12, meaning first time find order issue, record the previous node.
// case two: 1, 12(first), 4(mid, but never used), 5, 9, 8, 2(last), meaning seconde time record the post node
// swap value of first and mid, or first and last.
// Time: O(N), using iterative: using stack: Space:(O(N))
void recoverTree(TreeNode* root) {
    // should init as nullptr
    TreeNode* first = nullptr, *mid = nullptr, *last = nullptr;
    stack<TreeNode *> s;
    TreeNode* p = root, * prev = nullptr;
    while(p != nullptr || !s.empty()) {
        if (p != nullptr) {
            s.push(p);
            p = p->left;
        } else {
            p = s.top();
            s.pop();
            if (prev != nullptr && p->val < prev->val) {
                if (first == nullptr) {
                    first = prev;
                    mid = p;
                } else {
                    last = p;
                    break;
                }
            }
            prev = p;
            p = p->right;
        }
    }
    // swap only swaps values!
    if (last == nullptr) {
        swap(first->val, mid->val);
    } else {
        swap(first->val, last->val);
    }
}

// using recursion
// Time: O(N), Space:(1)
class Solution {
public:
    TreeNode* first = nullptr, *mid = nullptr, *last = nullptr;
    TreeNode* prev = nullptr;
    
    void inorderTraversal(TreeNode* root) {
        if(root->left) inorderTraversal(root->left);
        if (prev != nullptr && root->val < prev->val) {
            if (first == nullptr) {
                first = prev;
                mid = root;
            } else {
                last = root;
                return;
            }
        }
        prev = root;
        if(root->right) inorderTraversal(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        // should init as nullptr
        TreeNode* p = root, * prev = nullptr;
        if(root) inorderTraversal(p);
        // swap only swaps values!
        if (last == nullptr) {
            swap(first->val, mid->val);
        } else {
            swap(first->val, last->val);
        }
    }
};