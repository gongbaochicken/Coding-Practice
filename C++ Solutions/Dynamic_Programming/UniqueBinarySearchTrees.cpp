//Unique Binary Search Trees 
//Tags: DP
/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//Solutions in C++:
class Solution {
public:
    int numTrees(int n) {
        //F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1)
        int F[n+1];
        F[0] = 1; 
        F[1] = 1;
        for(int i = 2; i <= n; i++){
            F[i] = 0;
            for(int j = 1; j <= i; j++){
                F[i] += F[j-1]*F[i-j];
            }
        }
        return F[n];
    }
};