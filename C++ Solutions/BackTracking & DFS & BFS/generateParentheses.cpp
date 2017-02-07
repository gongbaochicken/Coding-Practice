//Generate Parentheses 
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
 "((()))",
 "(()())",
 "(())()",
 "()(())",
 "()()()"
]

 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n == 0) return ans;
        string str = "";
        backTracking(n, 0, str, ans);
        return ans;
    }

    void backTracking(int left, int right, string str, vector<string>& ans){
        if(left == 0 && right == 0){
            ans.push_back(str);
            return;
        }
        if(left > 0){
            backTracking(left-1, right+1, str + '(', ans);
        }
        if(right > 0){
            backTracking(left, right-1,str + ')', ans);
        }
    }
};
