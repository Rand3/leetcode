class Solution {
public:
	bool search(int A[], int n, int target) {
		// https://oj.leetcode.com/problems/search-in-rotated-sorted-array-ii/
		//
		// Follow up for https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
		// Suppose a sorted array is rotated at some pivot unknown to you beforehand.
		// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
		// You are given a target value to search. If found return its index, otherwise return -1.
		// What if duplicates elements in the array are allowed? 
		// Would this affect the run-time complexity? How and why?

		int begin = 0;
		int end = n - 1;
		while (begin <= end) {
			int middle = begin + (end - begin) / 2;
			if (A[middle] == target) {
				return true;
			}
			if (A[begin] == A[middle]) {
				begin++;
			}
			else if (A[middle] == A[end]) {
				end--;
			}
			else if (A[begin] < A[middle]) {
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
		return false;
	}
};
