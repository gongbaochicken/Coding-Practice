// 247. Strobogrammatic Number II
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

Example:

Input:  n = 2
Output: ["11","69","88","96"]
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
    	return helper(n, n);
    }

 private:
 	vector<string> helper(int n, int m){
        vector<string> ans;
        if(n == 0) {
        	return {""};
        }
        if(n == 1) {
        	return {"0", "1", "8"};
		}
		vector<string> v = helper(n-2, m);
		for(auto str: v){
			if(n != m) ans.push_back("0" + str + "0"); //最外层不要
			ans.push_back("1" + str + "1");
			ans.push_back("8" + str + "8");
			ans.push_back("6" + str + "9");
			ans.push_back("9" + str + "6");
		}
		return ans;
 	}
};