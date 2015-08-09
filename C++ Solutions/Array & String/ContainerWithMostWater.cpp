//Container With Most Water
//Tags: Array, 2 pointers
/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container. 
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        //if(height.size() == 0 || height.size() == 1) return 0;
        int i = 0, j = height.size()-1;
        int area = 0;
        while(i < j){
            area = max(area, (j-i) * min(height[i], height[j]));
            if(height[i] > height[j]) j--;
            else i++;
        }
        return area;
    }
};