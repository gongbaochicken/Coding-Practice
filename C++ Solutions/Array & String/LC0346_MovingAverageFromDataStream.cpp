/*
Given a stream of integers and a window size, calculate the moving average of all integers in 
the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
*/

// Using Queue
// Amortized Time Cost: O(1), Space: O(size)
class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        itsSize = size;
        currSum = 0.0;
    }
    
    double next(int val) {
        q.push(val);
        if (q.size() > itsSize) {
            int firstVal = q.front();
            q.pop();
            currSum += val - firstVal;
        } else {
            currSum += val;
        }
        return currSum / q.size();
    }
    
private:
    int itsSize;
    double currSum;
    queue<int> q;
};