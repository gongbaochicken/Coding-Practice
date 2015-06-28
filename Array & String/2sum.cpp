// Given an array of integers, find two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they add up to the target, 
// where index1 must be less than index2. Please note that your returned answers (both index1 and index2) 
// are not zero-based.

// You may assume that each input would have exactly one solution.

// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2 


//Solution 1:
//76ms

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mapping;
        vector<int> result;
        for (int i=0; i<numbers.size(); i++) {
            mapping[numbers[i]]=i;
        }
        for (int j=0; j<numbers.size(); j++) {
            int gap=target-numbers[j];
            if (mapping.find(gap) != mapping.end()) {
                  if(mapping[gap]>j) {
                    result.push_back(j+1);
                    result.push_back(mapping[gap]+1);
                    break;
                  }
            }
        }
        return result;    
    }
};


Hashtable: 24 ms,O(n), O(n) space

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> table;
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if(table.find(target - x) != table.end()){
                result.push_back(table[target - x] + 1);
                result.push_back(i + 1);
                break;
            }
            table[x] = i;
        }
        return result;
    }
};
