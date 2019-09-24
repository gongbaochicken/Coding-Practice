/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

//Basic Calculator II
//Tags: String
/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/

class Solution {
public:
    int calculate(string s) {
        long result = 0, cur = 0;
        char op = '+';
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            if(isdigit(s[i])){
                long num = s[i] - '0';
                while(i < s.size() - 1 && isdigit(s[i+1])){
                    num = num*10 + s[++i] - '0';
                }
                switch(op){
                    case '+' : cur += num; break;
                    case '-' : cur -= num; break;
                    case '*' : cur *= num; break;
                    case '/' : cur /= num; break;
                }
            } else {
                if(s[i] == '+' || s[i] == '-'){
                    result += cur;
                    cur = 0;
                }
                op = s[i];
            }
        }
        return static_cast<int>(result + cur);
    }
};