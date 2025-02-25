/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/

// stamp: *

// Solution 1: DFS
// Time: O(N^2)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        genHelper(res, "", n, 0);
        return res;
    }

    void genHelper(vector<string>& res, string s, int leftParentheses, int rightNeed) {
        if (leftParentheses == 0 && rightNeed == 0) {
            res.push_back(s);
            return;
        }

        if (leftParentheses > 0) {
            genHelper(res, s + '(', leftParentheses - 1, rightNeed + 1);
        }
        if (rightNeed > 0) {
            genHelper(res, s + ')', leftParentheses, rightNeed - 1);
        }
    }
};

// Other Solutions: BFS / DP