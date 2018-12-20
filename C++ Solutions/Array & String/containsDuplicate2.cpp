// Contains Duplicate II 

// Given an array of integers and an integer k, find out whether there there are two 
// distinct indices i and j in the array such that nums[i] = nums[j] and the difference 
// between i and j is at most k.

//Solution 1: Using stl::map;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1){return false;}
        map<int, int> IntMap;
        for(int i = 0; i < nums.size(); i++){
            if(IntMap.find(nums[i]) != IntMap.end()){
                if((i - IntMap[nums[i]]) <= k){
                    return true;
                }
            }
            IntMap[nums[i]] = i;
        }
        return false;
    }
};

//Test Time: 72ms


//Solution 2: boost::unordered_map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() <= 1){return false;}
        unordered_map<int, int> IntMap;
        for(int i = 0; i < nums.size(); i++){
            if(IntMap.find(nums[i]) != IntMap.end()){
                if((i - IntMap[nums[i]]) <= k){
                    return true;
                }
            }
            IntMap[nums[i]] = i;
        }
        return false;
    }
};

//Test Time: 32ms

//So, if there is no need to reorder the map elements, it would be better to use bootst::unordered_map.


