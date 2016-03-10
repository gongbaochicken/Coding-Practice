//Sort Colors
/*
 Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem. 
*/

//Solution 1: O(N), 1 pass and count
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0};
        for(int i = 0; i < nums.size(); i++){
            switch(nums[i]){
                case 0:
                    count[0]++;
                    break;
                case 1:
                    count[1]++;
                    break;
                case 2:
                    count[2]++;
                    break;
                default:
                    break;
            }
        }
        fill(nums.begin(), nums.begin()+count[0], 0);
        fill(nums.begin()+count[0], nums.begin()+count[0] + count[1], 1);
        fill(nums.begin()+count[0]+count[1], nums.end(), 2);
    }
};


//Solution 2: O(N), 1 Pass, 2 pointers:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, l = 0, h = nums.size()-1;
        while(i <= h){
            if(nums[i] < 1){
                swap(nums[i++], nums[l++]);
            }else if(nums[i] > 1){
                swap(nums[i], nums[h--]);
            }else{
                i++;
            }
        }
    }
};
