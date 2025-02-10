/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

// Solution 1: Prioirty Queue, O(NlogN)
class Solution {
private:
	struct compare{
		bool operator()(pair<int, int>& a, pair<int, int>& b){
			return a.second < b.second;
		}
	};

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> ans;
    	if(k == 0) return ans;
    	unordered_map<int, int> m;
    	for(auto num: nums){
            m[num]++;
    	}
    	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
    	for(auto item: m){
            q.push(item);
    	}

    	while(k--){
    		ans.push_back(q.top().first);
            q.pop();
    	}
    	return ans;        
    }
};

// Solution2: Bucket Sort, Time:O(N), Space: O(N)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.empty()) return ans;
        unordered_map<int, int> m;
        int maxValue = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxValue = max(maxValue, ++m[nums[i]]);
        }
        unordered_map<int, vector<int>> bucket;
        for (auto x: m) {
            bucket[x.second].push_back(x.first);
        }
        for (int i = maxValue; i >= 0; --i) {
            if (bucket.find(i) == bucket.end()) continue;
            while (!bucket[i].empty()) {
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};