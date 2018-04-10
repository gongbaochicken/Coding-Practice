//N-ary Tree Topics:

//Suppose we have a n-ary tree defined as below:
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


// N-ary Tree Preorder:
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root){return ans;}
        stack<Node*> st;
        Node* cur = root;
        while(cur != NULL || !st.empty()){
            if(cur){
              ans.push_back(cur->val);
              for(int i = cur->children.size() -1; i >=0; i--){
                  st.push(cur->children[i]);
              }
              cur = nullptr; //important
            }else{
               cur = st.top();
               st.pop();
            }
        }
        return ans;
    }
};


//Preorder: Recursion
class Solution {
public:
    void recursion(Node* curr ,vector<int>& ans) {
        if(!curr){
            return;
        }
        ans.push_back(curr->val);
        for (Node* treeNode : curr->children) {
            recursion(treeNode, ans);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root){return ans;}
        recursion(root, ans);
        return ans;
    }
};


//postorder
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root == nullptr) return ans;
        Node* curr;
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            curr = st.top();
            st.pop();
            if(curr != nullptr) {
                ans.push_back(curr->val);
                for(int i = 0; i < curr->children.size(); i++){
                    st.push(curr->children[i]);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//level traversal
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        vector<int> level;
        queue<Node*> curr, next;
        curr.push(root);
        while(!curr.empty()){
            while(!curr.empty()){
                Node* node = curr.front();
                curr.pop();
                level.push_back(node->val);
                for(int i = 0; i < node->children.size(); i++){
                    next.push(node->children[i]);
                }
            }
            ans.push_back(level);
            level.clear();
            swap(curr, next);
        }
        return ans;
    }
};
