//Count Complete Tree Nodes 
/*Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely 
filled, and all nodes in the last level are as far left as possible. It can have 
between 1 and 2h nodes inclusive at the last level h.
*/

//Solution in C++:
class Solution {
public:
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while(root) { 
            root = root->left;
            height++;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        if (root->left == NULL && root->right == NULL) {return 1;}
        //if (root->right == NULL) {return 2;}
    
        int left_height = getLeftHeight(root->left);
        int right_height = getLeftHeight(root->right);
        
        if(left_height == right_height) {
            return powTwo(left_height) + countNodes(root->right);
        }
        return powTwo(right_height) + countNodes(root->left);
    }
    
    int powTwo(int a){
        if(a == 0) return 1;
        if(a == 1) return 2;//This line can make it speed up about 70ms
        if(a % 2 == 0){
            return powTwo(a/2) * powTwo(a/2);
        }else{
            return 2 * powTwo(a/2) * powTwo(a/2);
        }
    }
};