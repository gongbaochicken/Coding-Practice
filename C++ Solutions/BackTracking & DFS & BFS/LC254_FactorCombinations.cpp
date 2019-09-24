/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/

// Backtrack
class Solution {
public:
    void helper(vector<int>& data, vector<vector<int>>& ans) {
        int start = 2;
        int x = data.back();
        data.pop_back();
        if (data.size() > 0) {
            start = data.back();
        }
        for (int i = start; i <= (x/i); ++i) {
            if (x%i == 0) {
                data.push_back(i);
                data.push_back(x/i);
                ans.push_back(data);
                helper(data, ans);
                data.pop_back();
                data.pop_back();
            }
        }
        data.push_back(x);
        return;
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> data;
        data.push_back(n);
        helper(data, ans);
        return ans;
    }
};