class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		// https://oj.leetcode.com/problems/search-for-a-range/
		//
		// Given a sorted array of integers, find the starting and ending position of a given target value.
		// Your algorithm's runtime complexity must be in the order of O(log n).
		// If the target is not found in the array, return [-1, -1].
		// For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

		vector<int> result = { -1, -1 };
		int left = 0;
		int right = n - 1;
		// find left boundary: left + 1 = right, A[left] < target, A[right] = target
		if (A[0] == target) {
			result[0] = 0;
		}
		else {
			while (left < right) {
				int middle = left + (right - left) / 2;
				if (A[middle] == target) {
					right = middle;
				}
				else if (A[middle] > target) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}
			if (A[right] != target) {
				return result;
			}
			result[0] = right;
		}
		// find right boundary: left + 1 = right, A[left] = target, A[right] > target
		if (A[n - 1] == target) {
			result[1] = n - 1;
		}
		else {
			left = result[0];
			right = n - 1;
			while (left < right) {
				int middle = left + (right + 1 - left) / 2; // Notice middle is calculated differently
				if (A[middle] == target) {
					left = middle;
				}
				else if (A[middle] > target) {
					right = middle - 1;
				}
				else {
					left = middle + 1;
				}
			}
			result[1] = left;
		}
		return result;
	}
	void test() {
		int A[] = { 5, 7, 7, 8, 8, 10 };
		int target = 8;
		vector<int> result = searchRange(A, sizeof(A) / sizeof(A[0]), target);
		cout << result[0] << ',' << result[1] << endl;
	}
};
