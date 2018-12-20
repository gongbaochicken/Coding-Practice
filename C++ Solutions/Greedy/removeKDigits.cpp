//402. Remove K Digits

/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.
 */

//Rule: if the current char is smaller than previous one, the previous one should be
//removed, when k>0.
//Solution 1: Using stack. However, stack consume a lot of space, and this also needs
//to handle several spcial case.
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0) return num;
        if(num.size() == 0 || k >= num.size()) return "0";

        stack<int> st;
        for(int i = 0; k > 0 && i < num.size(); i++){
            char c = num[i];
            while(!st.empty() && c < num[st.top()] && k){
                int index = st.top();
                st.pop();
                num.erase(num.begin()+index);
                k--;
                i--;//since erase one index
            }
            st.push(i);
        }
        //It's possible the whole stirng is in ascending order
        while(k > 0) {num.pop_back(); k--;}

        //trim front 0s.
        int s = 0;
        while (s < (int)num.size()-1 && num[s]=='0')  s++;
        num.erase(0, s);

        //if the empty stirng, it expects to be 0.
        return num=="" ? "0" : num;
    }
};
