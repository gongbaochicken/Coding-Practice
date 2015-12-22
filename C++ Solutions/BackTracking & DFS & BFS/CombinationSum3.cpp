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

//Solution: Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        if(k == 0) return ans;
        vector<int> curr;
        bs(ans, curr, 1, k, n);
        return ans;
    }
    
    void bs(vector<vector<int>>& ans, vector<int>& curr, int start, int k, int target){
        if(target == 0 && k == 0){
            ans.push_back(curr);
            return;
        }
        if(target < 0){
            return;
        }
        for(int i = start; i <= 9; i++){
            curr.push_back(i);
            bs(ans, curr, i+1, k-1, target-i);
            curr.pop_back();
        }
    }
};