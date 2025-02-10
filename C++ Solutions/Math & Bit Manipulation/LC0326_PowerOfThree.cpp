// 326. Power of Three
/*
Given an integer, write a function to determine if it is a power of three.

Example 1:
Input: 27
Output: true

Example 2:
Input: 0
Output: false

Example 3:
Input: 9
Output: true

Example 4:
Input: 45
Output: false

Follow up:
Could you do it without using any loop / recursion?
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while(n > 1) {
            if (n%3 != 0) return false;
            n /= 3;
        }
        return n == 1;
    }
};

// Other thought in C#:
public bool IsPowerOfThree(int n)
{
if( n <= 0){return false;}
decimal a = (decimal)Math.Log(n, 3);
return (int)a == a;
}

// Other thought in C++:
bool isPowerOfThree(int n) {
    if (n == 0 || n < 0) return false;
    if (1162261467 % n == 0) return true; // 3^19 is the maximum number of power of 3 within Int.
    else return false;
}
