// 163. Missing Ranges
/*
Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]
*/

class Solution {
public:
    void addRange(int l, int r, vector<string>& ans) {
        if (l > r) return;
        string s = l == r ? to_string(l) : to_string(l) + "->" + to_string(r);
        ans.push_back(s);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        int n = nums.size();
        if (n == 0) {
            addRange(lower, upper, ans);
            return ans;
        }
        for(int i = 0; i <= n; i++) {
            int l = (i == 0) ? lower : nums[i - 1] + 1;
            int r = (i == n) ? upper : nums[i] - 1;
            addRange(l, r, ans);
        }
        return ans;
    }
};