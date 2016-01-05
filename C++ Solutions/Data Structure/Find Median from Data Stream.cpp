//Find Median from Data Stream

/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(minHeap.empty() || num > minHeap.top()){
            minHeap.push(num);
        }else{
            maxHeap.push(num);
        }
        
        if(maxHeap.size() > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if(maxHeap.size()+1 < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int m = maxHeap.size(), n = minHeap.size();
        if((m+n)%2 == 0){
            return (maxHeap.top()+minHeap.top())/2.0;
        }else{
            return minHeap.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();