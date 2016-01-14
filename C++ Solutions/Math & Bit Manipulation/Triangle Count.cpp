//Triangle Count

/*
Given an array of integers, how many three numbers can be found in the array, 
so that we can build an triangle whose three edges length is the three numbers 
that we find?
*/


class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        if(S.size() < 3) return 0;
        sort(S.begin(), S.end());
        int ans = 0;
        for(int i = 2; i < S.size(); i++){
            int k = 0, j = i-1;
            while(k < j){
                if(S[k] + S[j] > S[i]){
                    ans += j-k;
                    j--;
                }else{
                    k++;
                }
            }
        }
        return ans;
    }
};