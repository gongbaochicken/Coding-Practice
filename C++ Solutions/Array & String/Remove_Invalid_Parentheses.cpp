//Remove Invalid Parentheses
/*
Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_rm = 0, right_rm = 0;
        for(auto c : s) {
            if(c == '(') {
                left_rm++;
            }
            if(c == ')') {
                if(left_rm != 0) left_rm--;
                else right_rm++;
            }
        }
        helper(s, 0, left_rm, right_rm, 0, "", result);
        return vector<string>(result.begin(), result.end());
    }
    
private:
    void helper(string s, int index, int left_rm, int right_rm, int pair, string path, unordered_set<string>& result) {
        if(index == s.size()){
            if(left_rm == 0 && right_rm == 0 && pair == 0) {
                result.insert(path);
            }
            return;
        }
        if(s[index] != '(' && s[index] != ')') {
            helper(s, index + 1, left_rm, right_rm, pair, path + s[index], result);
        }
        else {
            if(s[index] == '(') {
                if(left_rm > 0) {
                    helper(s, index + 1, left_rm - 1, right_rm, pair, path, result); //path没有加，相当于remove
                }
                helper(s, index + 1, left_rm, right_rm, pair + 1, path + s[index], result); //有了左边，一定有右边,open pair+1
            }
            if(s[index] == ')') {
                if(right_rm > 0) {
                    helper(s, index + 1, left_rm, right_rm - 1, pair, path, result);
                }
                if(pair > 0) {
                    helper(s, index + 1, left_rm, right_rm, pair - 1, path + s[index], result);
                }
            }
        }
    }
};