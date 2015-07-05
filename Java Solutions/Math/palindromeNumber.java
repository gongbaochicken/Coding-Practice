//LeetCode: Palindrome Number
//Determine whether an integer is a palindrome. Do this without extra space.

public class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) {
            div *= 10; 
        }
        while (x != 0) {
            int lastDigit = x % 10;
            int leftPart = x / div;
            if (leftPart != lastDigit) return false;
            x = (x % div) / 10;
            //cut the head and the tail
            div /= 100;
        }
        return true;
    }
}