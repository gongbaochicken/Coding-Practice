//91. Decode Ways
/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:
Input: "12" Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).

Example 2:
Input: "226" Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

//Solution: DP
//Time: O(N), Space: O(1), using space optimization
class Solution {
public:
    // prev:dp[i-2], curr:dp[i-1]
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        int prev = 1, curr = 1;
        for(int i = 1; i < s.size(); ++i){
            int temp = curr; //for assigning dp[i-2] = dp[i-1] later
            if(s[i] == '0'){
                //dp[i] = dp[i-1]
                curr = prev;
                if(s[i-1] >= '3' || s[i-1] <= '0') return 0;
            }
            else if(s[i-1] == '1' || s[i-1] == '2' && s[i] <= '6'){
                //dp[i] = dp[i-1] + dp[i-2]
                curr += prev;
            }
            prev = temp;
        }
        return curr;
    }
};