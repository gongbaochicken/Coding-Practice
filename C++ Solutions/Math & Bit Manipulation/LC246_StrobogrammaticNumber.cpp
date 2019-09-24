// 246. Strobogrammatic Number
/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

Example 1:
Input:  "69"
Output: true

Example 2:
Input:  "88"
Output: true

Example 3:
Input:  "962"
Output: false
*/

class Solution {
public:
    bool isStrobogrammatic(string num) {
        if(num.size() < 1) return false;
        int l = 0, r = num.size() -1;
        while(l <= r){
        	if(num[l] == num[r]){
        		if(num[l] != '0' && num[l] != '1' && num[r] != '8'){
        			return false;
        		}
        	}else{
        		if(!((num[l] == '6' && num[r] == '9') || (num[l] == '9' && num[r] == '6'))){
        			return false;
        		}
        	}
	        l++;
			r--;
        }
        return true;
    }
};