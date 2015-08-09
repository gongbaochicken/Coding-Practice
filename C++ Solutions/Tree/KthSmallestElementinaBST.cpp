
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
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* p = root;
        while(p != NULL || !st.empty()){
            if(p != NULL){
                st.push(p);
                p = p->left;
            }else{
                p = st.top();
                st.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> order;
        order = inorderTraversal(root);
        return order[k-1];
    }
};