// 239. Sliding Window Maximum
// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
// For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
// Therefore, return the max sliding window as [3,3,5,5,6,7].

//Solution: Use deque to main a window, which should follow 2 rules.
//rule 1: In the window, the elements are descending orders. The front
//is the maximum element.
//rule 2: The window contains index to avoid repeating issues.
//Time Complexisity: O(N)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        if(k == 0 || nums.empty()) return ans;
        dq.push_back(0);
        //unless k==1, otherwise ans should not keep this value.
        if(k == 1) ans.push_back(nums[0]);
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[dq.back()]){
                dq.push_back(i);
            }else{
                while(!dq.empty() && nums[i] >= nums[dq.back()]){
                  dq.pop_back();
                }
                dq.push_back(i);
            }
            //check if the front element is expired
            if(i-dq.front() == k){
                dq.pop_front();
            }
            //Only when the window size is reached, it starts to push value to ans
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
