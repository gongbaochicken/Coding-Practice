/*####Question: 
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

      ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


####My solution:
I will choose stack to store the numbers, before they do arithmetic operations, and to store the temporary result. Once we find an arithmetic operator in the input vector, we pop out the top 2 numbers to do arithmetic operations. 

Traps: 
1. Please pay attention to the order when we pop the top 2 numbers out.
2. If the vector only contains one string, the result should be the number transferred from that string.
3. When we check whether a string is a number, don't forget about the integers with "minus".

*/

class Solution {
	bool checkNum(string input){
    	for(int i = 0; i < input.length(); i++){
       		if(isdigit(input[i])) return true;
       	}
       	return false;
   	}
   	
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 0) return 0;
        int result = 0;
        if(tokens.size() == 1){
            result = stoi(tokens[0]);
        }
        stack<int> stk;
        for(int i = 0; i < tokens.size(); i++){
            if(checkNum(tokens[i])){
                int k = stoi(tokens[i]);
                stk.push(k);
            }
            else{
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if (tokens[i] == "+"){
                    result = a + b;
                    stk.push(result);
                }
                else if(tokens[i] == "-"){
                    result = a - b;
                    stk.push(result);
                }
                else if(tokens[i] == "*"){
                    result = a * b;
                    stk.push(result);
                }
                else if(tokens[i] == "/"){
                    result = a/b;
                    stk.push(result);
                }
            }
        }
        return result;
    }
    
};
