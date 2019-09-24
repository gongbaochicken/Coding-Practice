/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person who have a height greater 
than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example
Input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
Output: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

// sort first, O(NlogN)
// Key: 矮子插队无所谓，高个子反正看不见。先按照高个子从大到小排序，在调整可见度
class Solution {
public:
    static bool comp(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first > p2.first || p1.first == p2.first && p1.second < p2.second;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> ans;
        for (const pair<int, int>& p: people) {
            ans.insert(ans.begin() + p.second, p);
        }
        return ans;
    }
};