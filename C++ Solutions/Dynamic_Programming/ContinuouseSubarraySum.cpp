//523. Continuous Subarray Sum

/* Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to the multiple of k, that is, sums up to n*k where n is also an integer.

Example 1:
Input: [23, 2, 4, 6, 7],  k=6
Output: True
Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.

Example 2:
Input: [23, 2, 6, 4, 7],  k=6
Output: True
Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.

Note:
    The length of the array won't exceed 10,000.
    You may assume the sum of all the numbers is in the range of a signed 32-bit integer.
*/

//Works, but the memory exceeds.
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        int m = nums.size();
        vector<vector<int> > dp(m, vector<int>(m, -1));
        for(int i = 0; i < m; ++i){
        	dp[i][i] = nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
        	for(int j = i; j < nums.size(); j++){
        		if(dp[i][j] < 0){
        			int repeat = dp[i+1][j-1] == -1? 0: dp[i+1][j-1];
        			int sum = dp[i+1][j] + dp[i][j-1] - repeat;
        			dp[i][j] = sum;
        			if(k == 0 && sum == 0 && j-i >= 1) {
        				return true;
        			}else if(k != 0 && sum%k == 0 && j-i>= 1){
        				return true;
        			}
        		}
        	}
        }
        return false;
    }
};

//Pass all the test. Time: O(N^2), Space: O(N).
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2) return false;
        int m = nums.size();
        vector<int> dp(m, 0);
        for(int i = 0; i < m; ++i){
        	dp[i] = nums[i];
        }
        for(int i = nums.size()-1; i >= 0; i--){
        	for(int j = i-1; j >= 0; j--){
            dp[i] += dp[j];
            if(k == 0 && dp[i] == 0){
              return true;
            }else if(k != 0 && dp[i]%k == 0){
              return true;
            }
        	}
        }
        return false;
    }
};

//Math way:
//We iterate through the input array exactly once, keeping track of the running sum mod k of the elements in the process. If we find that a running sum value at index j has been previously seen before in some earlier index i in the array, 
//then we know that the sub-array (i,j] contains a desired sum.
