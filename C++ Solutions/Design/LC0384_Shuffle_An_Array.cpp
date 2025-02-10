/*
Shuffle a set of numbers without duplicates.

Example:
// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/

class Solution {
public:
    Solution(vector<int> nums) {
        prev = nums;
        curr = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        curr = prev;
        return curr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if (curr.size() == 0) return vector<int>();
        for(int i = 0; i < curr.size(); i++) {
            swap(curr[i], curr[rand()%curr.size()]);
        }
        return curr;
    }

private:
    vector<int> prev, curr;
};