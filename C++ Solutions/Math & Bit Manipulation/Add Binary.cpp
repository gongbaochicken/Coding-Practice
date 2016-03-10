//Add Binary
/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string s;
        for(int i = a.size()-1, j = b.size()-1; i >= 0 || j >= 0; i--, j--){
            int A = (i >= 0) ? a[i]-'0':0;
            int B = (j >= 0) ? b[j]-'0':0;
            int val = (A+B+carry)%2;
            carry = (A+B+carry)/2;
            s = to_string(val) + s;
        }
        if(carry){
            s = to_string(carry) + s;
        }
        return s;
    }
};