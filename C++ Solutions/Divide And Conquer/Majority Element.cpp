//Majority Element
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

//Using Map
//Time: O(N), Space: O(k);
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int majority = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = 1;
            }else{
                map[nums[i]]++;
                if(map[nums[i]] > nums.size()/2){
                    majority = nums[i];
                    break;
                }
            }
        }
        return majority;
    }
};

//Using vote:
//Time: O(n), space:O(1) 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0], vote = 1;
        for(int i = 1; i < nums.size(); i++){   //i starts from 1
            if(vote == 0){
                vote++;
                majority = nums[i];
            }else if(majority == nums[i]){
                vote++;
            }else{
                vote--;
            }
        }
        return majority;
    }
};