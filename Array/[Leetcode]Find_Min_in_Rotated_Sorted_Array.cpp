/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
*/

class Solution {
public:
  int findMin(vector<int> &num) {
    int start=0, last=num.size()-1;
    while(start < last){
      int mid=(start+last)/2;
      if(num[mid] < num[last]){
	last = mid;
      }
      else{
	start = mid + 1;
      }
    }
    return num[start];
  }
};
