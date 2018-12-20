/*
We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?

Note that our partition must use every number in A, and that scores are not necessarily integers.

Example:
Input:  A = [9,1,2,3,9] K = 3
Output: 20

Explanation: 
The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
We could have also partitioned A into [9, 1], [2], [3, 9], for example.
That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
 
Note:
1 <= A.length <= 100.
1 <= A[i] <= 10000.
1 <= K <= A.length.
Answers within 10^-6 of the correct answer will be accepted as correct.
*/

// DP, O(kN^2), Space: O(k*N)
// dp[k][j], max avg sum of first i elemnts with k groups
// Init: dp[1][i], avg(a[0] - a[i-1])
// Transition: dp[k][i] = max(dp[k-1][j] + avg(a[j+1],..., a[i]))
// Return dp[K][n]
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (A.size() == 1) return A[0];
        const int n = A.size();
        vector<vector<double>> dp(K+1, vector<double>(n+1));
        vector<double> sums(n+1, 0.0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i-1] + A[i-1];
            dp[1][i] = (sums[i])/i;
        }
        for (int k = 2; k < K+1; ++k) {
            for (int i = k; i <= n; ++i) { // doesn't make sense to have k groups if i < k.
                for (int j = k-1; j < i; ++j) {
                    dp[k][i] = max(dp[k][i], dp[k-1][j] + (sums[i]-sums[j])/(i-j));
                }
            }
        }
        return dp[K][n];
    }
}; 

// DP + Reuse array  space: O(N)
// dp   [0, 1, 2, 3, 4, 5 ]
// temp [   X, X, X, X .....        ]
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        if (A.size() == 1) return A[0];
        const int n = A.size();
        vector<double> dp(n+1, 0.0);
        vector<double> sums(n+1, 0.0);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i-1] + A[i-1];
            dp[i] = static_cast<double>(sums[i]/i);
        }
        for (int k = 2; k < K+1; ++k) {
            vector<double> temp(n+1, 0);
            for (int i = k; i <= n; ++i) {
                for (int j = k-1; j < i; ++j) {
                    temp[i] = max(temp[i], dp[j] + (sums[i]-sums[j])/(i-j));
                }
            }
            swap(dp, temp);
        }
        return dp[n];
    }
};