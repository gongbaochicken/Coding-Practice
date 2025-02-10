//Populating Next Right Pointers in Each Node II
/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
// BFS
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        Node* prev = nullptr;
        int prevLevel = -1;
        while(!q.empty()) {
            Node* x = q.front().first;
            int level = q.front().second;
            q.pop();
            if(x->left) q.push({x->left, level+1});
            if(x->right) q.push({x->right,level+1});
            if(prev && level == prevLevel) {
                prev->next = x;
            }
            prev = x;
            prevLevel = level;
        }
        return root;
    }
};