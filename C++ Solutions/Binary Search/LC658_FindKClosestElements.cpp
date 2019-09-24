// 658. Find K Closest Elements
/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Step 1: Find position
        int start = 0, end = arr.size() - 1, diff = INT_MAX;
        int pos = -1;
        while(start + 1 < end){
            int mid = start + (end - start) / 2;
            int gap = abs(arr[mid] - x);
            if(gap < diff) {
                pos = mid;
                diff = gap;
            }
            if(arr[mid] <= x) start = mid;
            else end = mid;
        }
        pos = abs(arr[start]-x)>abs(arr[end]-x)? end: start;

        //Step2: search left and right
        int l = pos-1, r = pos+1;
        vector<int> ans;
        ans.push_back(arr[pos]);
        int rest = k-1;
        while(r < arr.size() && l >= 0 && rest--) {
            if(abs(x- arr[l]) <= abs(x - arr[r])){
                ans.insert(ans.begin(), arr[l--]);
            }else{
                ans.push_back(arr[r++]);
            }
        }

        //Step 3: Post-processing
        if(r == arr.size()){
            while(rest--){
                ans.insert(ans.begin(), arr[l--]);
            }
        }else if(l < 0) {
            while(rest--){
                ans.push_back(arr[r++]);
            }
        }
        return ans;
    }
};