//85. Maximal Rectangle

// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// For example, given the following matrix:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Return 6.

class Solution {
public:
    void maxRectFromBottom(vector<int>& bottomVector, int& max){
      stack<int> st;
      bottomVector.push_back(-1);
      st.push(-1);
      for(int i = 0; i < bottomVector.size(); ++i){
          while(st.top() >= 0 && bottomVector[i] < bottomVector[st.top()]){
            int index = st.top();
            st.pop();
            int left = st.empty()? 0:st.top();
            int area = bottomVector[index]*(i - left -1);
            max = max > area? max: area;
          }
          st.push(i);
      }
      bottomVector.pop_back();
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        vector<int> bottomVector(matrix[0].size(), 0);
        int max = 0;
        for(int i = 0; i < matrix.size(); i++){
          for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j]- '0' == 0){
              bottomVector[j] = 0;
            }else{
              bottomVector[j] += (matrix[i][j] - '0');
            }
          }
          maxRectFromBottom(bottomVector, max);
        }
        return max;
    }
};
