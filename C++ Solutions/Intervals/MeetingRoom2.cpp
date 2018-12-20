//253. Meeting Rooms II
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
//Solution: O(N*lgN)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        vector<pair<int, int>> events;
        for(int i = 0; i < intervals.size(); i++){
            events.push_back({intervals[i].start, 1});
            events.push_back({intervals[i].end, -1});
        }
        sort(events.begin(), events.end());
        int curr = 0;
        int maxCurr = 0;
        for(auto event: events){
            curr += event.second;
            maxCurr = max(maxCurr, curr);
        }
        return maxCurr;
    }
};
