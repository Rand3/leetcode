class Solution {
public:
	int search(int A[], int n, int target) {
		// https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
		//
		// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
		// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
		// You are given a target value to search. If found return its index, otherwise return -1.
		// You may assume no duplicate exists in the array.

		// ref: http://leetcode.com/2010/04/searching-element-in-rotated-array.html
		int begin = 0;
		int end = n - 1;
		while (begin <= end) {
			int middle = begin + (end - begin) / 2;
			if (A[middle] == target) {
				return middle;
			}
			if (A[begin] <= A[middle]) {
				if (A[begin] <= target && target < A[middle]) {
					end = middle - 1;
				}
				else {
					begin = middle + 1;
				}
			}
			else {
				if (A[middle] < target && target <= A[end]) {
					begin = middle + 1;
				}
				else {
					end = middle - 1;
				}
			}
		}
		return -1;
	}
};
