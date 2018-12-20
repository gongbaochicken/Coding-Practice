//Sqrt(x)

/*
Implement int sqrt(int x).

Compute and return the square root of x, 
where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are 
truncated and only the integer part of the result is returned.

Example 1:
Input: 4  Output: 2

Example 2:
Input: 8  Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int start = 0, end = INT_MAX;
        int mid;
        while(true) {
            mid = start + (end-start)/2;
            if(mid > x/mid) {
                end = mid-1;
            }else{
                if(mid+1 > x/(mid+1)){
                    return mid;
                }
                start = mid+1;
            }
        }
    }
};

//Power(x, n)

/*
Implement pow(x, n), which calculates x raised to the power 
n (xn).

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:
    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]
*/

class Solution {
public:
    double myPow(double x, int n) {
        if(n >= 0) return power(x, n);
        else return 1.0/power(x, -n);
    }
    
    double power(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        double temp = power(x, n/2);
        if(n%2 == 0){
            return temp*temp;
        }else{
            return temp*temp*x;
        }
    }
};