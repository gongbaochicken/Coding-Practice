//Power of Two
// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int count = 0;
        for(int i = 0; i < 32; i++){
            int bit = (n >> i) & 1;
            if(bit == 1) count++;
            if(count > 1){
                return false;
            }
        }
        if(count == 1) return true;
    }
};

// return (n > 0) && !(n & (n-1));
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    return (n & (n-1)) == 0;
}
