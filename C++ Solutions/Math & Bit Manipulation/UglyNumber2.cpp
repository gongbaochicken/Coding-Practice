//Ugly Number II 
/*
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number.
*/

/*
(1) 1×2, 2×2, 3×2, 4×2, 5×2, …
(2) 1×3, 2×3, 3×3, 4×3, 5×3, …
(3) 1×5, 2×5, 3×5, 4×5, 5×5, …
*/

//Solution(Draft version:)
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 1) return 0;
        int index2 = 0, index3 = 0, index5 = 0, x = 1;
        vector<int> buff;
        buff.clear();
        buff.push_back(x);
        int count = n;
        while(count--){
            int v2 = 2*buff[index2], v3 = 3*buff[index3], v5 = 5*buff[index5];
            x = min(min(v2, v3), v5);
            if(x == v2) index2 += 1; 
            if(x == v3) index3 += 1;
            if(x == v5) index5 += 1; 
            buff.push_back(x);
        }
        return buff[n-1];
    }
};

//Solution(A slightly concise version:)
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 1) return 0;
        int index2 = 0, index3 = 0, index5 = 0, x = 1;
        vector<int> buff(1, 1);
        while(--n){
            int v2 = 2*buff[index2], v3 = 3*buff[index3], v5 = 5*buff[index5];
            x = min(min(v2, v3), v5);
            if(x == v2) index2 += 1; 
            if(x == v3) index3 += 1;
            if(x == v5) index5 += 1; 
            buff.push_back(x);
        }
        return x;
    }
};

