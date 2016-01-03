//Rectangle Area
/*
https://leetcode.com/problems/rectangle-area/
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(isOverlap(A, B, C, D, E, F, G, H) == false) {
            return ((C-A)*(D-B) + (G-E)*(H-F));
        }
        int newA = max(A, E);
        int newB = max(B, F);
        int newC = min(C, G);
        int newD = min(D, H);
        return (C-A)*(D-B) + (G-E)*(H-F) - (newC-newA)*(newD-newB);
    }
    
    
    bool isOverlap(int A, int B, int C, int D, int E, int F, int G, int H){
        if (A > G || B > H || C < E || F > D){
            return false;
        }
        return true;
    }
};