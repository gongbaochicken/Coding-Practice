//Two Sum II

/*Given an array of integers, find how many pairs in the array such that 
their sum is bigger than a specific target number. Please return the number of pairs.
*/

//Time: O(NlogN) 
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int ans = 0;
        while(l < r){
            if(nums[l] + nums[r] > target){
                ans += r-l;
                r--;
            }else{
                l++;
            }
        }
        return ans;
    }
};