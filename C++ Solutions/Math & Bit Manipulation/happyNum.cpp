/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following 
process: Starting with any positive integer, replace the 
number by the sum of the squares of its digits, and repeat
the process until the number equals 1 (where it will stay),
 or it loops endlessly in a cycle which does not include 1. 
 Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
12 + 0^2 + 0^2 = 1
*/

//MySolution
class Solution {
private:
    int squaremap[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
public:
    bool isHappy(int n) {
        set<int> visited;
        while(visited.find(n) == visited.end()){
            visited.insert(n);
            n = sum(n);
            if(n == 1) return true;
        }
        return false;
    }
    
    
    int sum(int n){
        int ans = 0;
        while(n){
            int bit = n%10;
            ans += squaremap[bit];
            n /= 10;
        }
        return ans;
    }
};



class Solution {
public:
    //Trick 1: map for small scale exponential operations
    int expoMap[10]={0,1,4,9,16,25,36,49,64,81};
    
    bool isHappy(int n) {
        if(n < 10){
            if(n == 1 || n == 7){ //Base case 
                return true;
            }else{
                return false;
            }
        }
        int m = breakSum(n); 
        return isHappy(m);
    }

    int breakSum(int n){
        int sum = 0;
        while(n){   //classic part in coding interview
            int a = n%10;
            sum += expoMap[a];
            n = n/10;
        }
        return sum;
    }
};