// 265. Paint House II
/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Example:

Input: [[1,5,3],[2,9,4]]
Output: 5
Explanation: Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
             Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5. 
Follow up:
Could you solve it in O(nk) runtime?
*/

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0 || costs[0].size() == 0) return 0;
        int n = costs.size(), k = costs[k].size();
        if(k == 1){
            return n > 1? -1: costs[0][0];
        }
        int prevMin = 0, prevMinIdx = -1, prevSecMin = 0;
        for(int i = 0; i < n; ++i){
            int currMin = INT_MAX, currMinIdx = -1, currSecMin = INT_MAX;
            for(int j = 0; j < k; ++j){
                int val = (j == prevMinIdx? prevSecMin: prevMin) + costs[i][j];
                if(currMinIdx == -1){
                    currMin = val;
                    currMinIdx = 0;
                }else if(val < currMin){
                    currSecMin = currMin;
                    currMin = val;
                    currMinIdx = j;
                }else if(val < currSecMin){
                    currSecMin = val;
                }
            }
            prevMin = currMin;
            prevMinIdx = currMinIdx;
            prevSecMin = currSecMin;
        }
        return prevMin;
    }
};