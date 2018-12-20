//Merge Intervals 
/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 */
class Solution {
 private:
     static bool compare(Interval& i1, Interval& i2){
         return i1.start < i2.start;
     }

    static bool isOverlap(Interval& i1, Interval& i2){
        return i1.end >= i2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), compare);
        ans.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            if(isOverlap(ans.back(), intervals[i])){
                ans.back().end = max(ans.back().end, intervals[i].end);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
