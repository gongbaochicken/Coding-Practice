//Find All Numbers Disappeared in an Array

//Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

// Find all the elements of [1, n] inclusive that do not appear in this array.
//
// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [5,6]


//Time: O(n), Sapce: O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        vector<int> v(nums.size()+1, 0);
        for(auto num: nums){
            v[num]++;
        }
        for(int i = 1; i < nums.size() + 1; i++){
            if(v[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Time: O(n), Sapce: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
