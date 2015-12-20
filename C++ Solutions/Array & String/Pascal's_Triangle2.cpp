//Pascal's Triangle II
/*Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev;
        if(rowIndex < 0) return prev;
        vector<int> first(1, 1);
        if(rowIndex == 0) return first;
        prev = first;
        for(int i = 1; i < rowIndex+1; i++){
            vector<int> curr(i+1, 1);
            for(int j = 1; j < i; j++){
                curr[j] = prev[j-1] + prev[j]; 
            }
            prev = curr;
        }
        return prev;
    }
};