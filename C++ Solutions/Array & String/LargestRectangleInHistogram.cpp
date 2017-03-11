//84. Largest Rectangle in Histogram
//
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
//find the area of largest rectangle in the histogram.
//For example,
//Given heights = [2,1,5,6,2,3],
//return 10.
//

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      stack<int> st;
      heights.push_back(-1);
      st.push(-1);
      int max = 0;
      for(int i = 0; i < heights.size(); ++i){
          while(st.top() >=0 && heights[i] < heights[st.top()]){
            int index = st.top();
            st.pop();
            int left = st.empty()? 0:st.top();
            int area = heights[index]*(i - left -1);
            max = max > area? max: area;
          }
          st.push(i);
      }
      heights.pop_back();
      return max;
    }
};
