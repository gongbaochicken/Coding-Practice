// 248. Strobogrammatic Number III
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.

Example:

Input: low = "50", high = "100"
Output: 3 
Explanation: 69, 88, and 96 are three strobogrammatic numbers.
*/

class Solution {
public:
	unordered_map<char, char> dict = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
    int strobogrammaticInRange(string low, string high) {
        int count = 0;
        for(int i = low.size(); i <= high.size(); i++){
        	string curr = "";
        	curr.resize(i, '0'); // "00000"
        	dfs(low, high, curr, 0, i-1, count);
        }
        return count;
    }
private:
	void dfs(const string& low, const string& high, string& curr, int l, int r, int& count){
		if(l > r){
			long currNum = stol(curr);
			if(currNum >= stol(low) && currNum <= stol(high)) {
                count++;
            }
			return;
		}
		for(const auto& pair: dict){
            // replace it with desire pairs
			curr[l] = pair.first, curr[r] = pair.second;
			if(curr.size() != 1 && curr[0] == '0') {
                // "080"
			    continue;
			}
			if(l == r && pair.first != pair.second) continue;
			dfs(low, high, curr, l+1, r-1, count);
		}
	}
};