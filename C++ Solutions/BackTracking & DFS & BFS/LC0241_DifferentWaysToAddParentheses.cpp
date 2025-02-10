/*
Given a string of numbers and operators, return all possible results from 
computing all the different possible ways to group numbers and operators. 
The valid operators are +, - and *.

Example 1:
Input: "2-1-1"  Output: [0, 2]
Explanation: 
((2-1)-1) = 0 
(2-(1-1)) = 2

Example 2:
Input: "2*3-4*5"  Output: [-34, -14, -10, -10, 10]
Explanation: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

// Solution: Intuitive---Divide and Conquer. Beat 100% on LC.
// Time & Space complexity is tricky. It depends on the number operator.
// Suppose there is K operators, then it would be K*O(K/2)*O(K/2)
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                string a = input.substr(0, i);
                string b = input.substr(i+1);
                for (auto v1: diffWaysToCompute(a)) {
                    for (auto v2: diffWaysToCompute(b)) {
                        int temp;
                        if (c == '+') {
                            temp = v1 + v2;
                        } else if (c == '-') {
                            temp = v1 - v2;
                        } else {
                            temp = v1 * v2;
                        }
                        ans.push_back(temp);
                    }
                 }
            }
        }
        return ans.size() > 0? ans: vector<int>{stoi(input)};
    }
};

// Optimization: Avoid repeated computation. Using top-down Memorization.
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> memory;
        return recursionHelper(input, memory);
    }
    
    vector<int> recursionHelper(string& input, unordered_map<string, vector<int>>& memory) {
        vector<int> ans;
        for (int i = 0; i < input.size(); ++i) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                string a = input.substr(0, i);
                string b = input.substr(i+1);
                vector<int> res1 = memory.find(a) != memory.end()? memory[a]: recursionHelper(a, memory);
                vector<int> res2 = memory.find(b) != memory.end()? memory[b]: recursionHelper(b, memory);
                for (auto v1: res1) {
                    for (auto v2: res2) {
                        int temp;
                        if (c == '+') {
                            temp = v1 + v2;
                        } else if (c == '-') {
                            temp = v1 - v2;
                        } else {
                            temp = v1 * v2;
                        }
                        ans.push_back(temp);
                    }
                 }
            }
        }
        ans = ans.size() > 0? ans: vector<int>{stoi(input)};
        memory[input] = ans;
        return ans;
    }
};