//Sqrt(x) 
//Tags: Binary Search, Math

//Implement int sqrt(int x).
//Compute and return the square root of x.

//Solution in C++:
class Solution {
public:
    int mySqrt(int x) {
        const float EPS = 0.00000001;  
        if(x == 0) return x;
        float X = x;  
        float val = x;//最终  
        float last = 0;//保存上一个计算的值          
        while(abs(val-last) > EPS){
            last = val;  
            val =(val + X/val) / 2;  
        }
        int ans = (int) val;    //change a float into an integer
        if(ans * ans > x)  ans--;  
        return ans;  
    }
};