// 293. Flip Game
/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your 
friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other 
person will be the winner.

Write a function to compute all possible states of the string after one valid move.

Example:

Input: s = "++++"
Output: 
[
  "--++",
  "+--+",
  "++--"
]
Note: If there is no valid move, return an empty list [].
*/

class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> ans;
        if(s.size() < 2) return ans;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '+' && s[i] == s[i-1]){
                char reverse = '-';
                s[i] = s[i-1] = reverse;
                // s[i-1] = reverse;
                ans.push_back(s);
                s[i] = s[i-1] = '+';
                // s[i-1] = '+';
            }
        }
        return ans;
    }
};