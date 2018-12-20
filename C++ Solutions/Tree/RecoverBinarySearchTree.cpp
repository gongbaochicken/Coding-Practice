//Recover Binary Search Tree
/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
*/


//Example:6, 3, 4, 5, 2------>We compare each node with its next one and we can find out that 
//6 is the first element to swap because 6 > 3 and 2 is the second element to swap because 2 < 5.
//So it is just inorder traversal.


class Solution {
public:
    TreeNode* pre, *first, * second;
    
    void recoverTree(TreeNode* root) {
        if(root == NULL) return ;
        pre = NULL, first = NULL, second = NULL;
        dfs(root);
        //swap
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
    
    void dfs(TreeNode* root){
        if(root == NULL) return ;
        dfs(root->left);
        if(pre != NULL && pre->val > root->val){ 
            if(first == NULL){ 
                first = pre;
                second = root; 
            }else{
                second = root;
            }
        }
        pre = root;
        dfs(root->right);
    }
};
