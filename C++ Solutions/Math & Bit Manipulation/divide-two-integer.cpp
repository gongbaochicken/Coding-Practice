// [Leetcode] Divide Two Integers
// Divide two integers without using multiplication, division and mod operator.
// If it is overflow, return MAX_INT. 

//Solution 1: Binary Search + Bit Manipulation
//Time: O(log n) Test: 14 ms

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend); 
        long long b = abs((long long)divisor); 
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1; //Deal with positive or negative
        long long result = 0;
  
        while(a >= b){
            long long c = b;
            for(int i = 0;a >= c;++i,c <<= 1){
                a -= c;
                result += 1 << i;
            }
        }
        result *= sign;        
        // If it is overflow, return MAX_INT.
        if (result > INT_MAX || result < INT_MIN){
            result = INT_MAX;
        }
        return result;
    }
};

//Solution 2: Exponentionalize (Smart solution inspired by dimal97psn @ Leetcode )
//Time: O(log n) Test: 8 ms

//Core Idea: a/b = {e^lg(a)} / {e^lg(b)} = e^(lg(a) - lg(b))
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        if(dividend == 0) return 0;
        long long x = (double) exp(log(fabs(dividend)) - log(fabs(divisor)));
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)){
            x = -x;
        }
        if(x > INT_MAX) {
            x = INT_MAX;
        }
        return x;
    }
};