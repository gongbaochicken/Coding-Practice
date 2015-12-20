//Valid Parentheses
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Subscribe to see which companies asked this question
*/
public class Solution {
    public boolean isValid(String s) {
        if(s.length() % 2 == 1) return false;
        Stack<Character> st = new Stack<Character>();
        for(int i = 0; i < s.length(); i++){
            char temp = s.charAt(i);
            if(temp == '(' || temp == '[' || temp == '{'){
                st.push(temp);
            }else{
                if(st.empty()) return false;
                if((temp == ')' && st.pop() != '(')
                || (temp == '}' && st.pop() != '{')
                || (temp == ']' && st.pop() != '[')) {return false;}
            }
        }
        return st.empty();
    }
}