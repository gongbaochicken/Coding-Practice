//449. Serialize and Deserialize BST
/*
Serialization is the process of converting a data structure or object into a sequence of 
bits so that it can be stored in a file or memory buffer, or transmitted across a network 
connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction 
on how your serialization/deserialization algorithm should work. You just need to ensure that 
a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible. 
*/


// general solution:
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
    		return "#!";
    	}
    	string ans = to_string(root->val) + "!";
    	ans += serialize(root->left);
    	ans += serialize(root->right);
        return ans;
    }

    TreeNode* deserializeHelper(queue<string>& temp){
    	string str = temp.front();
    	temp.pop();
		if(str == "#"){
			return nullptr;
		}
		int val = stoi(str);
		TreeNode* node = new TreeNode(val);
		if(!temp.empty()) node->left = deserializeHelper(temp);
		if(!temp.empty()) node->right = deserializeHelper(temp);
		return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
		string token;

		queue<string> temp;
		while(std::getline(ss, token, '!')) {
			temp.push(token);
		}

		return deserializeHelper(temp);
    }
};


// Another sotluion (from Web) using BST feature. (faster)
class Codec {
public:

	string serialize(TreeNode* root) {
		if (root == NULL) return "";
		char buff[4];
		memcpy(buff, &root->val, sizeof(buff));
        string mid;
		mid.append(buff, sizeof(buff));
		return mid + this->serialize(root->left) + this->serialize(root->right);
	}

	TreeNode* deserialize(string data) {
		int len = data.size() / 4; 
		if (len < 1) return NULL;
		
        const int* pos = (const int*)data.c_str();
		int rootVal = pos[0];
		TreeNode* root = new TreeNode(rootVal);
		int i = 1;
		while (i < len && pos[i] < rootVal) i++; //find the root of right subtree
        if (1 < i) root->left = deserialize(string(&data[4], &data[i * 4])); //left
		if (i < len) root->right = deserialize(string(&data[i * 4], &data[len * 4])); //right
		return root;
	}
};