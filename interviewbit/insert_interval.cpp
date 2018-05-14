//57. Insert Interval
/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/





//Solution
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int index = 0;
        while(index < intervals.size() && intervals[index].end < newInterval.start) {
            res.push_back(intervals[index++]);
        }
        while(index < intervals.size() && intervals[index].start <= newInterval.end) {
            newInterval.start = min(intervals[index].start, newInterval.start);
            newInterval.end = max(intervals[index].end, newInterval.end);
            index++;
        }
        res.push_back(newInterval);
        while(index < intervals.size()) {
            res.push_back(intervals[index++]);
        }
        return res;
    }
};