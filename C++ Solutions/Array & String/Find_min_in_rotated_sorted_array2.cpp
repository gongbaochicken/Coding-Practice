//Find Minimum in Rotated Sorted Array II
// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// The array may contain duplicates.

class Solution {
public:
    int findMin(vector<int> &num) {
        int start=0;
        int last=num.size()-1;
        int mid=0;
        while(start<last){
            if(num[start]<num[last])
            break;
            mid=(start+last)/2;
            if(num[mid]>num[last]){
                start=mid+1;
            }else if(num[mid]<num[last]){
                last=mid;
            }else{
                last--;    //think why cannot "mid++"
                start++;
             }
        }
        return num[start];
    }
};
