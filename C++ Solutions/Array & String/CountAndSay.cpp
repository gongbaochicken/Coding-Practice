//Count and Say
/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.
*/

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string s = "1";
        while(--n){
            string ans = "";
            for(int i = 0; i < s.size(); i++){
                int count = 1;
                while(i < s.size()-1 && s[i] == s[i+1]) {
                    count++;
                    i++;
                }
                ans += to_string(count) + s[i];
            }
            s = ans;
        }
        return s;
    }
};