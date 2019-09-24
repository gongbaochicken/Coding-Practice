/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

// Naive:
// Time complexity : O(n)O(n) - range sum query, O(1)O(1) - update query

// Solution:
// Time: Build: Time complexity : O(n), n+n/2+n/4+n/8+…+1≈2n; Space: O(n)
//       Update Time complexity : O(logn) levels. Space complexity : O(1)O(1).
//       Query Time complexity : O(logn), space: O(1)
struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode* left, *right;
    SegmentTreeNode(int s, int e): start(s), end(e), sum(0), left(nullptr), right(nullptr) {}
    SegmentTreeNode(int s, int e, int Sum): start(s), end(e), sum(Sum), left(nullptr), right(nullptr) {}
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        root = buildTree(nums, 0, nums.size()-1);
    }
    
    void update(int i, int val) {
        int whatever = updateTree(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return queryTree(root, i, j);
    }

private:
    SegmentTreeNode* root;

    SegmentTreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) {
            SegmentTreeNode* root = new SegmentTreeNode(start, end, nums[start]);
            return root;
        }
        SegmentTreeNode* root = new SegmentTreeNode(start, end);
        int mid = start + (end - start)/2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int updateTree(SegmentTreeNode* root, int i, int val) {
        if (root == nullptr) return 0;
        int diff;
        if (root->start == root->end) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }
        int mid = root->start + (root->end - root->start)/2;
        if (i > mid) {
            diff = updateTree(root->right, i, val);
        } else {
            diff = updateTree(root->left, i, val);
        }
        root->sum = root->sum + diff;
        return diff;
    }
    
    int queryTree(SegmentTreeNode* root, int i, int j) {
        if(root == nullptr) return 0;
        if(root->start == i && root->end == j) return root->sum;
        int mid = root->start + (root->end - root->start)/2;
        if(i > mid) return queryTree(root->right, i, j);
        if(j <= mid) return queryTree(root->left, i, j);
        return queryTree(root->left, i, mid) + queryTree(root->right, mid+1, j);
    }
};
