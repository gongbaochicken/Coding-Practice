//Majority Number III
/*Given an array of integers and a number k, the majority number 
is the number that occurs more than 1/k of the size of the array.

Find it.*/

//Solution:
//Time: O(N), Space: O(k)
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            if(map.find(nums[i]) != map.end()){
                map[nums[i]]++;
            }else{
                map[nums[i]] = 1;
            }
        }
        
        int threshold = nums.size()/k;
        for(auto x: map){
            if(x.second > threshold){
                return x.first;
            }
        }
        return 0;
    }
};