//Combination Sum II
/*Tags: Backtracking
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations i
n C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
    All numbers (including target) will be positive integers.
    Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    The solution set must not contain duplicate combinations.

For example, given candidate set 10,1,2,7,6,1,5 and target 8,
A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]
*/

//Solution: 
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int> > res;
        std::vector<int> combination;
        combinationGene(candidates, target, res, combination, 0);
        return res;
    }
private:
    void combinationGene(std::vector<int> &candidates, int target, std::vector<std::vector<int> > &res, std::vector<int> &combination, int begin) {
        if  (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){
            if (i == begin || candidates[i] != candidates[i - 1]) {//Why we sort before
                combination.push_back(candidates[i]);
                combinationGene(candidates, target - candidates[i], res, combination, i + 1);
                combination.pop_back();
            }
        }
    }
};