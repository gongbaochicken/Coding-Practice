//Search for a Range
//Tags: Binary Search
/*Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

//Use Binary Search Twice
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int l = -1, r = -1;
        int start = 0, end = nums.size()-1;

        //first pos
        while(start+1 < end){
            int mid = start + (end - start)/2;
            if(nums[mid] >= target) end = mid;
            else start = mid;
        }
        if(nums[start] == target){
            l = start;
        }else if(nums[end] == target){
            l = end;
        }else{
            return {-1, -1};
        }

       //last pos
        start = l, end = nums.size()-1;
        while(start+1 < end){
            int mid = start + (end - start)/2;
            if(nums[mid] <= target) start = mid;
            else end = mid;
        }
        if(nums[end] == target){
            r = end;
        }else if(nums[start] == target){
            r = start;
        }else{
            return {-1, -1};
        }
        return {l, r};
    }
};
//Time: O(log n)
