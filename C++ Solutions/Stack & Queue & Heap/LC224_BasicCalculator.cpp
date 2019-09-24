// 224. Basic Calculator
/*
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

Example 1:

Input: "1 + 1"
Output: 2
Example 2:

Input: " 2-1 + 2 "
Output: 3
Example 3:

Input: "(1+(4+5+2)-3)+(6+8)"
Output: 23
Note:
You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/

// Solution:
int calculate(string s) {
    stack<long> nums, ops;
    long num = 0, ans = 0;
    int sign = 1;
    for (char c : s) { 
        if (isdigit(c)) {
            num = num * 10 + c - '0';
        } else {
            ans += sign * num;
            num = 0;
            if (c == '+') {
                sign = 1;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '(') {
                nums.push(ans);
                ops.push(sign);
                ans = 0;
                sign = 1;
            } else if (c == ')' && ops.size()) {
                ans = ops.top() * ans + nums.top();
                ops.pop();
                nums.pop();
            }
        }
    }
    // Adding the rest last part
    ans += sign * num;
    return (int) ans;
}