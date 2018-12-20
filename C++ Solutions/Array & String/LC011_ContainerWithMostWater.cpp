//Container With Most Water
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int maxArea = 0;
        while(l < r){
            if(height[l] < height[r]){
                int newArea = (r-l)*height[l];
                maxArea = max(maxArea, newArea);
                l++;
            }else{
                int newArea = (r-l)*height[r];
                maxArea = max(maxArea, newArea);
                r--;
            }
        }
        return maxArea;
    }
};