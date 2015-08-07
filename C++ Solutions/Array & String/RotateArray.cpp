Rotate Array
/*Tags: 
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] 
is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 
3 different ways to solve this problem. 
*/

//Solution 1: std::vector.insert();
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int offset = nums.size() - k % nums.size();
        vector<int> part(nums.begin()+offset, nums.end());
        nums.resize(offset);
        nums.insert(nums.begin(), part.begin(), part.end());
    }
};



//Solution 2: reverse 3 times!
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};