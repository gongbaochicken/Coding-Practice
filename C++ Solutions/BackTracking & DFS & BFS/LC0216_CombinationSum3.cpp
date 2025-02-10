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
        vector<vector<int>> ans;
        vector<int> curr;
        backTracking(ans, curr, n, 1, k, k);
        return ans;
    }

    void backTracking(vector<vector<int>>& ans, vector<int>& curr, int n, int begin, int need, int size){
        if(n == 0 && curr.size() == size){
            ans.push_back(curr);
            return;
        }
        if(need == 0 || curr.size() > size) return;
        for(int i = begin; i < 10; ++i){
            curr.push_back(i);
            backTracking(ans, curr, n - i, i + 1, need-1, size);
            curr.pop_back();
        }
    }
};
