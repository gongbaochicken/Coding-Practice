//Pow(x, n) 
//Tags: Binary Search
//Implement pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        if (n>=0) return power(x, n);
        else return 1.0/power(x,-n);
    }
    
    double power(double x, int n){
        if(n == 0) return 1;
        double ans = power(x, n/2);
        if(n%2 == 0){
            return ans * ans;
        }else{
            return ans * ans * x;
        }
    }
};