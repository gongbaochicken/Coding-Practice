//Insert Interval 
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        if(intervals.size() == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        int i = 0;
        while(i < intervals.size() && intervals[i].end < newInterval.start) i++;
        int m = i;
        while(i < intervals.size() && intervals[i].start <= newInterval.end){
            newInterval = Interval(min(intervals[i].start, newInterval.start), max(intervals[i].end, newInterval.end));
            i++;
        }
        if(m < i)  intervals.erase(intervals.begin() + m, intervals.begin() + i);
        intervals.insert(intervals.begin() + m, newInterval);
        return intervals;
    }
};
