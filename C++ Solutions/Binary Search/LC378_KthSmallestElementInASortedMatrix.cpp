// 378. Kth Smallest Element in a Sorted Matrix
/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
return 13.

Note: 
You may assume k is always valid, 1 ≤ k ≤ n^2.
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0) return 0;
        int l = matrix[0][0], r = matrix[n-1][n-1];
        while(l < r){
            int mid = l + (r-l)/2;
            int num = 0;
            for(int i = 0; i < n; i++){
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }   
            if(num < k){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        return l;
    }
};