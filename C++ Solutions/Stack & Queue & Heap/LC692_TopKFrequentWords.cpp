// Top K Frequent Words
/*
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower 
alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements. Input words contain only lowercase letters.

Follow up:
Try to solve it in O(n log k) time and O(n) extra space.
*/

//beat 99.87%
class Solution {
public:
    typedef pair<int, string> node;
    struct compare {
        bool operator()(const node& p1, const node& p2){
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        if (k == 0 || words.empty()) return ans;
        unordered_map<string, int> count;
        for (int i = 0; i < words.size(); ++i) {
            ++count[words[i]];
        }
        priority_queue<node, vector<node>, compare> minHeap;
        for (auto& pair: count){
            //very important
            if (minHeap.size() == k && pair.second < minHeap.top().first) {
                continue;
            }
            minHeap.push(make_pair(pair.second, pair.first));
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        while(!minHeap.empty()) {
            string temp = minHeap.top().second;
            minHeap.pop();
            ans.insert(ans.begin(), temp);
        }
        return ans;
    }
};