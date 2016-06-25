//Combination Sum III 
//Tags: Backtracking
/*
Find all possible combinations of k numbers that add up to a number n, given that 
only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:[[1,2,4]]

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationGene(n, res, combination, 1, k);
        return res;
    }
private:
    void combinationGene(int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin, int need) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }
        if(need == 0){
            return;
        }
        for (int i = begin; i < 10 && target >= i*need + need*(need-1)/2; ++i){
                combination.push_back(i);
                combinationGene(target-i, res, combination, i+1, need-1);
                combination.pop_back();
        }
    }
};