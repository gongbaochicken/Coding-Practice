//252. Meeting Rooms
/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
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
 //Solution: Use sort. O(N*lgN).
class Solution {
 private:
     static bool compare(Interval& i1, Interval& i2){
         return i1.start < i2.start;
     }

 public:
     bool canAttendMeetings(vector<Interval>& intervals) {
         sort(intervals.begin(), intervals.end(), compare);
         for(int i = 1; i < intervals.size(); i++){
             if(intervals[i-1].end > intervals[i].start){
                return false;
             }
         }
         return true;
     }
};
