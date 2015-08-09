//Minimum Size Subarray Sum
/*Tags: 2 pointers
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. 
*/

//Solution:
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int len = INT_MAX, pos = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(sum >= s){
                len = min(len, i - pos + 1);
                sum -= nums[pos++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};