//Largest Number
/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    //Sort String
    string largestNumber(vector<int>& nums) {
        string ans;
        if(nums.size() == 0) return ans;
        sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        for(auto num: nums){
            ans += to_string(num);
        }
        ans = ans[0]=='0'? "0":ans;
        return ans;
    }
};