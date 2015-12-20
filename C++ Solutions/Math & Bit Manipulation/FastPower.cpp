//Fast Power
//Divide and Conquer
/*
Calculate the an % b where a, b and n are all 32bit integers.

Have you met this question in a real interview? Yes
Example
For 231 % 3 = 2

For 1001000 % 1000 = 0
*/

//Solution:
class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        long result = longFastPower(a, b, n);
        return (int) result;
    }
        
    long longFastPower(int a,  int b, int n){
        if(a == 0) return 0;
        if(n == 0) return 1%b;
        if(n == 1) return a%b;
        long temp = longFastPower(a, b, n/2);
        temp *= temp;
        temp = temp % b;
        if(n % 2 == 0){
            return temp;
        }else{
            return temp * (a % b) %b;
        }
    }
};