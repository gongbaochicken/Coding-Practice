//Find Peak Element
//Tags: Array, Binary Search
/*A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

Note: Your solution should be in logarithmic complexity.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return binarySearchHelper(nums, 0, nums.size()-1);
    }
    
    int binarySearchHelper(vector<int>& nums, int begin, int end){
        if(begin == end) return begin;
        if(begin+1 == end) {
            if(nums[begin] > nums[end]) return begin;
            else return end;
        }
        //Since num[-1] = num[n] = -∞
        //If num[i-1] < num[i] > num[i+1], then num[i] is peak
        //If num[i-1] < num[i] < num[i+1], then num[i+1...n-1] must contains a peak
        //If num[i-1] > num[i] > num[i+1], then num[0...i-1] must contains a peak
        //If num[i-1] > num[i] < num[i+1], then both sides have peak (n is num.length).Doesn't matter, just choose any of the above 2 situation
        while(begin < end){
            int m = (begin + end) / 2;
            if(nums[m] > nums[m-1] && nums[m] > nums[m+1]) return m;
            if(nums[m] > nums[m-1] && nums[m] < nums[m+1]) return binarySearchHelper(nums, m+1, end);
            else return binarySearchHelper(nums, begin, m-1);
        }
    }
};

//Time: O(nlogn)