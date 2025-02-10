//Letter Combinations of a Phone Number
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

// BackTracking
class Solution {
private:
    string dir[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string curr;
        backTracking(digits, ans, curr, 0);
        return ans;
    }
    
    void backTracking(string digits, vector<string>& ans, string curr, int start){
        if(start == digits.size()){
            ans.push_back(curr);
            return;
        }
        int index = digits[start] - '0';
        for(int i = 0; i < dir[index].size(); i++){
            curr.push_back(dir[index][i]);
            backTracking(digits, ans, curr, start+1);
            curr.pop_back();
        }
    }
};