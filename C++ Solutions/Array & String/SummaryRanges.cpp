//Summary Ranges
//Tags: Easy, 2 pointers
/*
Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
*/

//Solution in C++

//Idea: use two pointers, and use std::to_string()
class Solution {
public:
    //two pointers
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        
        int pos = 0;
        while(pos < nums.size()){
            int val = nums[pos];
            if(pos+1 < nums.size() && nums[pos] + 1== nums[pos+1]){
                while(pos+1 < nums.size() && nums[pos] + 1== nums[pos+1]){
                    pos++;
                }
                result.push_back(to_string(val) + "->" + to_string(nums[pos]));
            }else{
                result.push_back(to_string(val));
            }
            pos++;
        }
        return result;
    }
};

//Time: O(n), Space: O(1)