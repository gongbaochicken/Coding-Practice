// 371. Sum of Two Integers
/*
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
Example 1:
Input: a = 1, b = 2
Output: 3

Example 2:
Input: a = -2, b = 3
Output: 1
*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum;
        while(b != 0){
            sum = a^b;
            b = (a&b) << 1;
            a = sum;
        }
        return sum;
    }
};