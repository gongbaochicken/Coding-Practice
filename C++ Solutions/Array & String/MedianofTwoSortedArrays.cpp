// Median of Two Sorted Arrays 

// There are two sorted arrays nums1 and nums2 of size m and n respectively. 
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

//Solution:
//(This solution is slow, I may modify this very soon.)

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if((m+n)%2==0) {
            return (getMed(A, m, B, n, (m+n)/2) + getMed(A, m, B, n, (m+n)/2+1))/2.0;
        }
        else{
            return getMed(A, m, B, n, (m+n)/2+1);
        }
    }
    int getMed(int A[], int m, int B[], int n, int k){
        if (m<=0) return B[k-1];
        if (n<=0) return A[k-1];
        if (k<=1) return min (A[0], B[0]);
        if ((m/2+n/2+1) >= k) {
            if (A[m/2]>B[n/2]) {
                return getMed(A, m/2, B, n, k);
            }else{
                return getMed(A, m, B, n/2, k);
            }
        }else{
            if (A[m/2]>B[n/2]) {
                return getMed(A, m, B+n/2+1, n-(n/2+1), k-(n/2+1));
            }else{
                return getMed(A+m/2+1, m-(m/2+1), B, n, k-(m/2+1));
            }
        }
    }
};