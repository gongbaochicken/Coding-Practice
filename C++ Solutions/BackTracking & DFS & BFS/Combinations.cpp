//Combinations 
/*Tags: DFS
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        if(n < k) return res;
        vector<int> temp(0, k); //Temp combination
        combineGenerator(res, temp, 0, 0, n, k);
        return res;
    }
    
    //num is the number in the temp vector
    void combineGenerator(vector<vector<int> > &res,vector<int> &temp,int start,int num,int n ,int k){
        if(num == k){ //Satisfy the requirement
            res.push_back(temp);
            return;
        }
        for(int i = start; i < n; i++){
            temp.push_back(i+1);
            combineGenerator(res, temp, i + 1, num + 1, n, k);
            temp.pop_back();
        }
    }
};