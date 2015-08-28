//Contains Duplicate III 
//Tags: set, STL
/*
Given an array of integers, find out whether there are two distinct indices i and j 
in the array such that the difference between nums[i] and nums[j] is at most t and 
the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> S;
        for(int i = 0; i < nums.size(); ++i){
            if(i > k) S.erase(nums[i - k -1]);
            auto pos = S.lower_bound(nums[i] - t);
            if(pos != S.end() && (*pos - t <=  nums[i])){
                return true;
            }
            S.insert(nums[i]);
        }
        return false;
    }
};