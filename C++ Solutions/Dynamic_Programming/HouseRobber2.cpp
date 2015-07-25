//House Robber 2
/*
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a circle. 
That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses
 remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the 
maximum amount of money you can rob tonight without alerting the police.
*/

//Solution in C++:

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
       
        //Either give up the first house, or the "end" house of the circle
        vector<int> case1(nums);
        vector<int>::iterator i = case1.begin();
        case1.erase(i);
       
        vector<int> case2(nums);
        case2.pop_back();
       
        int v1 = robLine(case1);
        int v2 = robLine(case2);
      return max(v1, v2);
    }
    
    int robLine(vector<int> &house){  //Size >= 2
        house[1] = max(house[1], house[0]);
        for(int i = 2; i < house.size(); i++){
            house[i] = max((house[i] + house[i-2]), house[i-1]);
        }
        return house[house.size() - 1];
    }
};