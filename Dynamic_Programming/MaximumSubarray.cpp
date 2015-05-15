/*Leetcode: Maximum Subarray 
Find the contiguous subarray within an array (containing at 
least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/

Solution: Dynamic Programming(C++)

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0, max = A[0];
        for (int i = 0; i < n; i++) {
            sum += A[i];
            if (sum > max)  max = sum;
            if (sum < 0)  sum = 0;
        }
        return max;
    }
};

Analysis:
Time: O(n),  Space: O(n)