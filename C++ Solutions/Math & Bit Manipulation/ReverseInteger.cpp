//Reverse Integer 
/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
 */


class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        bool positive = true;
        long ans = 0;
        while(x != 0){
            //if(abs(ans) > INT_MAX/10) return 0;
            ans = ans*10 + x%10;
            x /= 10;
        }
        return (int)(abs(ans) > INT_MAX? 0 : ans);
    }
};
