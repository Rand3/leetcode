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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		// https://oj.leetcode.com/problems/insert-interval/
		//
		// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
		// You may assume that the intervals were initially sorted according to their start times.
		// Example 1: Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
		// Example 2: Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
		// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 

		// Insert the new interval according to the start value
		vector<Interval> result;
		int size = (int)intervals.size();
		int i;
		for (i = 0; i < size; i++) {
			if (intervals[i].start >= newInterval.start) {
				break;
			}
			result.push_back(intervals[i]);
		}
		if (i > 0 && intervals[i - 1].end >= newInterval.start) {
			newInterval.start = intervals[i - 1].start;
			newInterval.end = max(newInterval.end, intervals[i - 1].end);
			result.pop_back();
		}
		for (; i < size; i++) {
			if (intervals[i].start > newInterval.end) {
				break;
			}
			newInterval.end = max(newInterval.end, intervals[i].end);
		}
		result.push_back(newInterval);
		for (; i < size; i++) {
			result.push_back(intervals[i]);
		}
		return result;
	}
	void test() {
		vector<Interval> intervals;
		vector<int> v = { 1, 2, 3, 5, 6, 7, 8, 10, 12, 16 };
		for (int i = 0; i < v.size(); i += 2) {
			intervals.push_back(Interval(v[i], v[i + 1]));
		}
		Interval newInterval(4, 9);
		insert(intervals, newInterval);
	}
};
