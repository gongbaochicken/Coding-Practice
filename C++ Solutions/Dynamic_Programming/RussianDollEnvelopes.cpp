/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
One envelope can fit into another if and only if both the width and height of one 
envelope is greater than the width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can 
Russian doll is 3 ([2,3] => [5,4] => [6,7]). 
*/

//Solution 1: ask maximum number ===> DP
//DP: Time:O(N^2), Space: O(N)
class Solution {
public:
    static bool compare(pair<int, int >& e1, pair<int, int>& e2) {
        return e1.first < e2.first;
    }

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size() < 2) return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), compare);
        int res = 0;
        // The max when use the i-th envelope as the out most envelopes
        vector<int> dp(envelopes.size());
        for(int i = 0; i < envelopes.size(); ++i){
            dp[i] = 1;
            for(int j = 0; j < i; ++j){
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second> envelopes[j].second) {
                    //If A can contains B, and B can cotains other 2(dp[B]=3), then A can contain at least other 3(dp[A]=4).
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};