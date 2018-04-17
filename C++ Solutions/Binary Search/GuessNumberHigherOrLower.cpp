//Guess Number Higher or Lower
/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number 
I picked.

Every time you guess wrong, I'll tell you whether the number 
is higher or lower.

You call a pre-defined API guess(int num) which returns 3 
possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example:
n = 10, I pick 6. Return 6.
*/

//solution:
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n == 1) return 1;
        int l = 1, r = n;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(guess(mid) == 0){
                return mid;
            }else if (guess(mid) == -1) {
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};

//Improve: make it more like template.
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if(n == 1) return 1;
        int l = 1, r = n;
        while(l+1 < r) {
            int mid = l + (r-l)/2;
            if(guess(mid) == 0){
                return mid;
            }else if (guess(mid) == -1) {
                r = mid;
            }else{
                l = mid;
            }
        }
        if(guess(l) == 0) return l;
        if(guess(r) == 0) return r;
    }
};