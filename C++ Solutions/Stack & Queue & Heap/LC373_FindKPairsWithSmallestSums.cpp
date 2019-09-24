// 373. Find K Pairs with Smallest Sums
/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]] 
Explanation: The first 3 pairs are returned from the sequence: 
             [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [1,1],[1,1]
Explanation: The first 2 pairs are returned from the sequence: 
             [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [1,3],[2,3]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if (nums1.empty() || nums2.empty()) {
            return res;
        }

        auto comp = [&](const pair<int, int>& pr1, const pair<int, int>& pr2) {
            return nums1[pr1.first] + nums2[pr1.second] > nums1[pr2.first] + nums2[pr2.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        int n1 = nums1.size(); // faster
        for (int i = 0; i < n1; ++i) {
            pq.push({i, 0});
        }

        int n2 = nums2.size(); // faster
        while (!pq.empty() && res.size() < (size_t)k) {
            auto pr = pq.top();
            pq.pop();
            res.push_back({nums1[pr.first], nums2[pr.second]});

            if (pr.second + 1 < n2) {
                pq.push({pr.first, pr.second + 1});
            }
        }
        return res;
    }
};