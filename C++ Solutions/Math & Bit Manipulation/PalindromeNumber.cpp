//Palindrome Number
/*Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

Subscribe to see which companies asked this question.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        int div = 1;
        while(x/div >= 10){
            div *= 10;
        }
        while(x != 0){
            int l = x/div;
            int r = x%10;
            if(l != r) return false;
            x = (x%div)/10;
            div = div/100;
        }
        return true;
    }
};
