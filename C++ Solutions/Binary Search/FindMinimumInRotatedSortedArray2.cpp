//Find Minimum in Rotated Sorted Array II
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// The array may contain duplicates.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, last = nums.size() - 1;
        while(start < last){
            if(nums[start] < nums[last]) break;
            int mid = (start + last) / 2;
            if(nums[mid] > nums[last]){
                start = mid + 1;
            }else if(nums[mid] < nums[last]){
                last = mid;
            }else{
                --last;    //think why cannot "mid++"
                ++start;
             }
        }
        return nums[start];
    }
};

//Template:
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l+1 < r){
            if(nums[l] < nums[r]) break;
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid;
            }else if(nums[mid] < nums[r]){
                r = mid;
            }else{
                ++l;
            }
        }
        return nums[l] > nums[r]? nums[r]: nums[l];   
    }
};
