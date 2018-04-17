//Find Minimum in Rotated Sorted Array
//Tags: Binary Search
/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.*/


/*
Case 1. The leftmost value is less than the rightmost value in the list: This means that the list is not rotated.
e.g> [1 2 3 4 5 6 7 ]. Then we just return the leftmost value in the list.

Case 2. The value in the middle of the list is greater than the leftmost and rightmost values in the list.
 e.g> [ 4 5 6 7 0 1 2 3 ]. Then we just discard the left part.

Case 3. The value in the middle of the list is less than the leftmost and rightmost values in the list.
e.g> [ 5 6 7 0 1 2 3 4 ]. Then we just discard the right part.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return nums[l];
    }
};


//Template:
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l + 1< r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid;
            }else{
                r = mid;
            }
        }
        return nums[l] > nums[r]? nums[r]: nums[l];   
    }
};