//Longest Increasing Subsequence
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n^2) complexity.
*/


//O(n^2) Solutions:
//DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        vector<int> LIS(nums.size(), 1);
        int len = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
            len = max(len, LIS[i]);
        }
        return len;
    }
};


//Improve by using binary search:ß
class Solution {
public:
    int bst(vector<int>& dp, int l, int r, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(dp[mid] > target){
                r = mid-1;
            }else if(dp[mid] < target){
                l = mid+1;
            }else{
                return mid;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int dpLen = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > dp[dpLen-1]){
                dp[dpLen++] = nums[i];
            }else{
                int indexInDP = bst(dp, 0, dpLen, nums[i]);
                dp[indexInDP] = nums[i];
            }
        }
        return dpLen;
    }
};