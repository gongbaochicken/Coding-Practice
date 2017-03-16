/*
Leetcode: Valid Parentheses
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid
but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if( s[i]=='(' || s[i]=='{' || s[i]=='[') {st.push(s[i]);}
            else{
                if(st.empty()) return false;
                if ((s[i]==')') && (st.top()!='(')) {return false;}
                if ((s[i]=='{') && (st.top()!='}')) {return false;}
                if ((s[i]=='[') && (st.top()!=']')) {return false;}
                st.pop();
            }
        }
        return st.empty();
    }
};


//Similar:
class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            char c = s[i];
            if(c == '(' || c == '[' || c=='{'){
                st.push(c);
            }else if(c == ')' && !st.empty() && st.top() == '('){
                st.pop();
            }else if(c == '}' && !st.empty() && st.top() == '{'){
                st.pop();
            }else if(c == ']' && !st.empty() && st.top() == '['){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
