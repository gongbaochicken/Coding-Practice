// 59. Spiral Matrix II
/*
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n < 1) return vector<vector<int>>();
        vector<vector<int>> ans(n, vector<int>(n));
        int r1 = 0, c1 = 0, r2 = n-1, c2 = n-1;
        int curr = 1;
        while(r1 <= r2 && c1 <= c2){
            spiral(curr, ans, r1++, r2--, c1++, c2--);
        }
        return ans;
    }

private:
    void spiral(int& curr, vector<vector<int>>& ans, int r1, int r2, int c1, int c2) {
        if(r1 == r2){
            for(int i = c1; i <= c2; ++i) ans[r1][i] = curr++;
        }else if(c1 == c2){
            for(int i = r1; i <= r2; ++i) ans[i][c1] = curr++;
        }else{
            int currR = r1, currC = c1;
            while(currC != c2) ans[r1][currC++] = curr++;
            while(currR != r2) ans[currR++][c2] = curr++;
            while(currC != c1) ans[r2][currC--] = curr++;
            while(currR != r1) ans[currR--][c1] = curr++;
        }
    }
};