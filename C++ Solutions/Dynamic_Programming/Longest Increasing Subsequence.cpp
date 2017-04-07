//Longest Increasing Subsequence
/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n^2) complexity.
*/

//O(n^2) Solutions:
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


//Improve by using binary search: O(NlogN)
class Solution {
public:
    int bsearch(vector<int>& ans, int target){
      int l = 0, r = ans.size()-1;
      while(l < r){
        int mid = (l+r)/2;
        if(ans[mid] >= target){
          r = mid;
        }else{
          l = mid+1;
        }
      }
      return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
          if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
          }else{
            //Cannot resize
            int index = bsearch(ans, nums[i]);
            ans[index] = nums[i];
          }
        }
        return ans.size();
    }
};
