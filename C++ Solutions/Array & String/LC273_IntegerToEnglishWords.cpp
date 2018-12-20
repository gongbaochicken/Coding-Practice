/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be 
less than 231 - 1.

Example 1:
Input: 123  Output: "One Hundred Twenty Three"

Example 2:
Input: 12345  Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:
Input: 1234567  Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Example 4:
Input: 1234567891  Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
*/

class Solution {
public:
    vector<string> level = {"", "Thousand ", "Million ", "Billion ", "Trillion "};
    vector<string> digit = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
    vector<string> tens = {"Ten ", "Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};
    vector<string> decades = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ","Ninety "};
    
    string convertLittlePart(int n) {
        string temp = "";
        int bit0 = n%10;
        n /= 10;
        int bit1 = n%10;
        n /= 10;
        if (bit1 == 0) {
            temp = digit[bit0];
        } else if (bit1 == 1) {
            temp = tens[bit0];
        } else if (bit1 > 1) {
            temp = decades[bit1] + digit[bit0];
        }
        int bit2 = n;
        if (bit2 > 0) {
            temp = digit[bit2] + "Hundred " + temp;
        }
        return temp;
    }
    
    string numberToWords(int num) {
        if (num == 0) return  "Zero";
        string ans;
        int levelCount = 0;
        while (num > 0) {
            int littleNum = num % 1000;
            num /= 1000;
            if (littleNum) {
                string temp = convertLittlePart(littleNum) + level[levelCount];
                ans = temp + ans;
            }
            levelCount++;
        }
        ans.pop_back();
        return ans;
    }
};