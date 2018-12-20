// Given a positive integer num, write a function which returns True if num is a perfect square 
// else False.

// Example 1:
// Input: 16  Returns: True

// Example 2:
// Input: 14 Returns: False

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 1, r = num/2; 
        while(l <= r){
        	long mid = (long) l + (r-l)/2;
        	long long temp = mid*mid;
        	if(temp == num){
        		return true;
        	}else if (temp > num){
        		r = mid-1;
        	}else{
        		l = mid+1;
        	}
        }
        return false;
    }
};