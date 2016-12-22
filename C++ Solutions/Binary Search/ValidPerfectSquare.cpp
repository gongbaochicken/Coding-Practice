//Valid Perfect Square
//Given a positive integer num, write a function which returns True if num is a perfect square else False.
//
// Note: Do not use any built-in library function such as sqrt.
//
// Example 1:
//
// Input: 16
// Returns: True
//
// Example 2:
//
// Input: 14
// Returns: False
//


//Solution 1: 1+3+5+7+... Time Complexity O(sqrt(N))
class Solution {
public:
    bool isPerfectSquare(int num) {
        //1+3+5+7+9...
        int i = 1;
        while(num > 0){
            num -= i;
            i += 2;
        }
        if(num == 0) return true;
        return false;
    }
};


//Solution 2: Binary Search, Time Complexity O(log(N))
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        while(l <= r){
            long mid = l + (r-l)/2;
            long sq = mid*mid;
            if(sq == num){
                return true;
            }else if(sq < num){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
};
