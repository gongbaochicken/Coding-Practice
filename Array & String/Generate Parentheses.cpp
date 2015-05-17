/*
Leetcode: Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 
*/

class Solution {
public:
    vector<string> ans;
    
    vector<string> generateParenthesis(int n) {
        helper("", n, 0);
        return ans;
    }
    
    void helper(string s, int leftParen, int right_need){
        if(leftParen == 0 && right_need == 0){
            ans.push_back(s);
            return;
        }
        if(leftParen > 0){
            helper(s + "(", leftParen - 1, right_need + 1);
        }
        if(right_need > 0){
            helper(s + ")", leftParen, right_need - 1);
        }
    }
};
