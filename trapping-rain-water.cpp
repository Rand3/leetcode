class Solution {
public:
	int trap(int A[], int n) {
		// https://oj.leetcode.com/problems/trapping-rain-water/
		//
		// Given n non-negative integers representing an elevation map where the width 
		// of each bar is 1, compute how much water it is able to trap after raining.
		// For example, Given [0,1,0,2,1,0,1,3,2,1,2,1] as illustrated below, where
		// 'X' represents the bar, 6 units of rain water '*' are being trapped.
		//   3        X
		//   2    X***XX*X
		//   1 _X*XX*XXXXXX
		//     010210132121

		int left = 0;
		int right = n - 1;
		int block = 0; // area of all 'blocks'
		int all = 0; // sum of 'blocks' and 'waters'
		int current_level = 0;
		while (left <= right) {
			int level = min(A[left], A[right]);
			if (level > current_level) {
				all += (level - current_level) * (right - left + 1);
				current_level = level;
			}
			if (A[left] < A[right]) {
				block += A[left];
				left++;
			}
			else {
				block += A[right];
				right--;
			}
		}
		return all - block;
	}
	void test() {
		int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1, 0 };
		int n = sizeof(A) / sizeof(int);
		for (int i = 0; i < n; i++) {
			int result = trap(A, i);
			cout << A[i] << " : " << result << endl;
		}
	}
};
