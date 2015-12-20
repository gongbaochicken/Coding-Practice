//Different Ways to Add Parentheses
/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (ispunct(c)){
                vector<int> al = diffWaysToCompute(input.substr(0, i));
                vector<int> bl = diffWaysToCompute(input.substr(i + 1));
                for (int x : al) {
                    for (int y : bl) {
                        if (c == '-') {
                            res.push_back(x - y);
                        } else if (c == '+') {
                            res.push_back(x + y);
                        } else if (c == '*') {
                            res.push_back(x * y);
                        }
                    }
                }
            }
        }
        if (res.size() == 0) {
            int x = atoi(input.c_str());
            res.push_back(x);
        }
        return res;
    }
};