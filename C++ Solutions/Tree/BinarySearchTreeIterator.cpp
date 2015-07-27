//Binary Search Tree Iterator 
/*Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/

/*
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

//Solution in C++:
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode *root) {
        save_left(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty()){
            return false;
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *top = st.top();
        st.pop();
        //Track back, if there exists right children, then save them to the stack for later use.
        if(top->right != NULL){
            save_left(top->right);
        }
        return top->val;
    }

    //Save the left(smaller) children in pre-order
    void save_left(TreeNode *root){
        TreeNode *p = root;
        while(p != NULL){
            st.push(p);
            p = p->left;
        }
    }
};