// Climbing Stairs 

// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


class Solution {
public:
    int climbStairs(int n) {
        if (n==0 || n==1) return 1;
        int a=1,b=1;
        int ans;
        for (int i=2; i<=n; i++) {
            ans=a+b;
            b=a;
            a=ans;
        }
        return ans;
    }
};