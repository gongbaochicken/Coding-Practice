//Minimum Size Subarray Sum
/*Tags: 2 pointers
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. 
*/

//Solution: 
// Using Queue, Time: O(N), Space: O(N)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        queue<int> q;
        if(nums.size() == 0) return 0;
        int len = INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
        	q.push(nums[i]);
        	sum += nums[i];
        	while(sum - q.front() >= s){
        		sum -= q.front();
        		q.pop();
        	}
        	if(sum >= s){
        		len = len > q.size()? q.size(): len;
        	}
        }
        return len == INT_MAX? 0: len;
    }
};


// Follow up Solution for Time O(NlogN):
// Since every number is positive, so their accumulated sum is ordered, so we can use binary search
// Having sum vector of size (n+1). sum[i] = sum[i-1] + nums[i-1], init sum[0] = 0
// Then from i = 1 -> n, value_to_search = s + sum[i - 1]; 
// (sum from i->j is sum[j]-sum[i]+nums[i] >= s ===> sum[j] >= s + sum[i]-nums[i] =====> sum[j] >= s+ sum[i-1]) !!
// Search lowerBound for this value and compare index with cached min length.