

/*
Numbers keep coming, return the median of numbers at every time a new number added.

Example
For numbers coming list: [1, 2, 3, 4, 5], return [1, 1, 2, 2, 3].
For numbers coming list: [4, 5, 1, 3, 2, 6, 0], return [4, 4, 4, 3, 3, 3, 3].
For numbers coming list: [2, 20, 100], return [2, 2, 20].

Challenge
Total run time in O(nlogn).
*/

//C++:
//MaxHeap: maintained the smaller half;
//MinHeap: maintained the larger half;
class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        vector<int> res;
        if(nums.size() == 0) return res;
        int median = nums[0];
        res.push_back(nums[0]);
        priority_queue<int> max, min;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < median){
                max.push(nums[i]);
            }else{
                min.push(-nums[i]);
            }
            //compare size of maxHeap and minHeap
            if(max.size() > min.size()){
                min.push(-median);
                median = max.top();
                max.pop();
            }else if(max.size()+1 < min.size()){
                max.push(median);
                median = -min.top();
                min.pop();
            }
            res.push_back(median);
        }
        return res;
    }
};
//Follow up: what if we need n/10th number?
//just keep the sizeof minHeap is 9 times of that of maxHeap

//Java:
class MedianFinder {
    
    PriorityQueue<Integer> maxheap = new PriorityQueue<Integer>();
    PriorityQueue<Integer> minheap = new PriorityQueue<Integer>(Collections.reverseOrder());
    
    // Adds a number into the data structure.
    public void addNum(int num) {
        maxheap.offer(num);
        minheap.offer(maxheap.poll());
        if(maxheap.size() < minheap.size()){
            maxheap.offer(minheap.poll());
        }
    }

    // Returns the median of current data stream
    public double findMedian() {
        return maxheap.size() == minheap.size() ? (double)(maxheap.peek() + minheap.peek()) / 2.0 : maxheap.peek();
    }
};