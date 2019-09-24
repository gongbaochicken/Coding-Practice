//Sqrt(x) 
//Tags: Binary Search, Math

//Implement int sqrt(int x).
//Compute and return the square root of x.

//Solution in C++:
// abylonian method for square root
float squareRoot(float n) 
{ 
  float x = n; 
  float y = 1; 
  float e = 0.000001; /* e decides the accuracy level*/
  while(x - y > e) 
  { 
    x = (x + y)/2; 
    y = n/x; 
  } 
  return x; 
}

//Solution 2: Binary Search
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 0, right = INT_MAX;
        while(left <= right){
            int mid = left + (right-left)/2;
            if (mid <= x/mid) {
                if((mid+1) > x/(mid+1)) return mid;
                left = mid + 1;
            } else {
                right = mid-1;
            }
        }
        return -1;
    }
};