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
    vector<Interval> merge(vector<Interval> &intervals) {
        // https://oj.leetcode.com/problems/merge-intervals/
        //
        // Given a collection of intervals, merge all overlapping intervals.
        // For example, Given [1,3],[2,6],[8,10],[15,18],
        // return [1,6],[8,10],[15,18]. 
        int size = (int)intervals.size();
        if (size <= 1) { return intervals; }
        vector<Interval> r;
        sort(intervals.begin(), intervals.end(), compByStart);
        // merge i1 and i2. notice i1.start <= i1.start
        //  i1[...]
        //   i2[.]
        //   i2[...]
        //          i2[..]
        r.push_back(intervals[0]);
        for (int i = 1; i < size; i++) {
            if (intervals[i].start <= r.back().end) {
                r.back().end = max(r.back().end, intervals[i].end);
            }
            else {
                r.push_back(intervals[i]);
            }
        }
        return r;
    }
    static bool compByStart(const Interval& a, const Interval &b) {
        return a.start < b.start;
    }
    void test() {
        vector<Interval> intervals = {
            { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 }
        };
        vector<Interval> result = merge(intervals);
    }
};
