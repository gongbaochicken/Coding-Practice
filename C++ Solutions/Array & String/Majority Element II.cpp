//Majority Element II

//Given an integer array of size n, 
//find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int x, y;
        for(auto num: nums){
            if(count1 == 0 || num == x){
                x = num;
                count1++;
            }else if(count2 == 0 || num == y){
                y = num;
                count2++;
            }else{
                count1--;
                count2--;
            }
        }
        count1 = 0, count2 = 0;
        for(auto num: nums){
            if(num == x) count1++;
            else if(num == y) count2++;
        }
        vector<int> res;
        if(count1 > nums.size()/3) res.push_back(x);
        if(count2 > nums.size()/3) res.push_back(y);
        return res;
    }
};