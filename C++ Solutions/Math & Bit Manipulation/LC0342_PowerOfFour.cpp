/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        // ensure num >= 1;
        if(num <= 0) return false;

        // ensure must be a power of 2.
        if(num & (num-1)) return false;

        return num & 0X55555555; //(0101 0101 0101 0101 0101 0101 0101)  
    }
};