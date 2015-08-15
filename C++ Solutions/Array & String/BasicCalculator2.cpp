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
        int result = 0, cur = 0;
        char op = '+';
        for(int i = s.find_first_not_of(' '); i < s.size(); i = s.find_first_not_of(' ', i)){
            if(isdigit(s[i])){
                int num = s[i] - '0';
                while(++i < s.size() && isdigit(s[i])){
                    num = num*10 + s[i] - '0';
                }
                switch(op){
                    case '+' : cur += num; break;
                    case '-' : cur -= num; break;
                    case '*' : cur *= num; break;
                    case '/' : cur /= num; break;
                }
            }
            else{
                if(s[i] == '+' || s[i] == '-'){
                    result += cur;
                    cur = 0;
                }
                op = s[i++];
            }
        }
        return result + cur;
    }
};