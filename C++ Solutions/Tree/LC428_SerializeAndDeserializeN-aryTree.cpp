// 428. Serialize and Deserialize N-ary Tree
/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize an N-ary tree. An N-ary tree is a rooted tree in which each node has no more than N children. 
There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that an N-ary tree can be serialized 
to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following 3-ary tree

as [1 [3[5 6] 2 4]]. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

Note:
N is in the range of [1, 1000]
Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
*/

/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        encode_dfs(root, s);
        return s;
    }

    void encode_dfs(Node* root, string& s){
        if(!root) return;
        s += " " + to_string(root->val) + " " + to_string(root->children.size());
        for(auto p:root->children) encode_dfs(p, s);
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    Node* decode(stringstream& ss){
        ss.peek(); 
        if(ss.eof()) return nullptr;
        auto root = new Node();
        int child_size;
        ss >> root->val >> child_size;
        for(int i=0; i < child_size;i++) root->children.push_back(decode(ss));                
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
