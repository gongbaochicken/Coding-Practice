//Next Permutation 
/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

//Solution 1:
//Inspired from: http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int i = n, j = 0;
        
		//From the right to the left, find the partition digit that violates the increasing trend;
		while(i && nums[i] <= nums[i-1]){
			i--;
		}
		
		//If i=0, so it must be "Last" permutation instance. 
		//So we need to go back to the beginning state. Just swap the whole vector, or use revserse().
		if(i == 0){
			for(int p = 0, q = nums.size()-1; p < q; p++, q--){
				swap(nums[p], nums[q]);
			}
			return;
		}
		
		//At this time, the partition index = i-1;
		//From the right to the left, find the first digit larger than the partition. Swap them.
		for(j = n; j > (i-1); j--){
		    if(nums[j] > nums[i-1]){
		        break;
		    }
		}
		swap(nums[j], nums[i-1]);
		
		//Sort the rest part behind the partition digit.
		sort(nums.begin() + i, nums.end());
    }
};



//Solution 2:
//Using std:next_permutation
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};