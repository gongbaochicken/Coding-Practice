/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) return "0";
        vector<int> ans(num1.size() + num2.size(), 0);
        for(int i = num1.size()-1; i >= 0; i--){
            for(int j = num2.size()-1; j >= 0; j--){
                int mul = (num1[i] - '0')*(num2[j] - '0') + ans[i+j+1];
                int high = i + j, low = i + j +1;
                ans[low] = mul%10; //first time
                ans[high] += mul/10;
            }
        }
        string s;
        for(int i = 0; i < ans.size(); ++i){
            if(ans[i] == 0 && s.size() == 0) continue;
            s += '0'+ ans[i]; // turn it to string
        }
        return s.size() == 0? "0" : s; // "0" * "0"
    }
};