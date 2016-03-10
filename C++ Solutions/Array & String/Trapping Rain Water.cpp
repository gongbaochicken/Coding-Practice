//Trapping Rain Water
/*
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int l = 0, r = height.size()-1;
        int leftMax = height[l], rightMax = height[r], second = 0;
        int ans = 0;
        while(l < r){
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);
            second = min(leftMax, rightMax);
            if(height[l] < height[r]){
                ans += second - height[l];
                l++;
            }else{
                ans += second - height[r];
                r--;
            }
        }
        return ans;
    }
};