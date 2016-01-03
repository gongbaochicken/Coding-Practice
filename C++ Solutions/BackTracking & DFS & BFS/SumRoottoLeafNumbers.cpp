//Sum Root to Leaf Numbers
/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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

 //Solution: BackTracking
class Solution {
public:
    int sumNumbers(TreeNode* root) {
       if(root == NULL) return 0;
       vector<int> nums;
       int curr = 0;
       sumHelper(nums, curr, root);
       int sum = 0;
       for(auto i: nums){
           sum += i;
       }
       return sum;
    }
    
    void sumHelper(vector<int>& nums, int curr, TreeNode* root){
        if(root->left == NULL && root->right == NULL) {
            int num = curr*10 + root->val;
            nums.push_back(num);
            return;
        }
        curr = curr*10 + root->val;
        if(root->left != NULL){
            sumHelper(nums, curr, root->left);
        }  
        if(root->right != NULL){
            sumHelper(nums, curr, root->right);
        }
    }
};