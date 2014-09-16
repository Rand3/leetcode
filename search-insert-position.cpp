class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		// https://oj.leetcode.com/problems/search-insert-position/
		//
		// Given a sorted array and a target value, return the index if the target is found. 
		// If not, return the index where it would be if it were inserted in order.
		// You may assume no duplicates in the array. Here are few examples.
		//   [1,3,5,6], 5 => 2
		//   [1,3,5,6], 2 => 1
		//   [1,3,5,6], 7 => 4
		//   [1,3,5,6], 0 => 0
		//
		if (n == 0) { return 0; }
		if (n == 1) { return (target <= A[0] ? 0 : 1); }
		int left = 0;
		int right = n - 1;
		while (left + 1 < right) {
			int middle = left + (right - left) / 2;
			if (target == A[middle]) {
				return middle;
			}
			else if (target < A[middle]) {
				right = middle;
			}
			else {
				left = middle;
			}
		}
		// left + 1 == right
		if (target <= A[left]) {
			return left;
		}
		else if (target <= A[right]) {
			return right;
		}
		else {
			return right + 1;
		}
	}
	void test() {
		//   [1,3,5,6], 5 => 2
		//   [1,3,5,6], 2 => 1
		//   [1,3,5,6], 7 => 4
		//   [1,3,5,6], 0 => 0
		struct TestCase {
			int target;
			int result;
			int v[4];
		};
		vector<TestCase> v = {
				{ 5, 2, { 1, 3, 5, 6 } },
				{ 2, 1, { 1, 3, 5, 6 } },
				{ 7, 4, { 1, 3, 5, 6 } },
				{ 0, 0, { 1, 3, 5, 6 } }
		};
		for (auto t : v) {
			int result = searchInsert(t.v, 4, t.target);
			if (result != t.result) {
				cout << "Expect: " << t.result << ", returned: " << result << endl;
			}
		}
	}
};
