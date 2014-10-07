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

		if (n <= 2) { return 0; }
		int left = 0;
		int right = n - 1;
		int width = right - left - 1;
		int height = min(A[left], A[right]);
		int total = height * width;
		while (width > 0) {
			width--;
			if (A[left] < A[right]) {
				left++;
				if (A[left] < height) {
					total -= A[left];
				}
				else {
					total -= height;
					int h2 = min(A[left], A[right]);
					total += (h2 - height) * width;
					height = h2;
				}
			}
			else {
				right--;
				if (A[right] < height) {
					total -= A[right];
				}
				else {
					total -= height;
					int h2 = min(A[left], A[right]);
					total += (h2 - height) * width;
					height = h2;
				}
			}
		}
		return total;
	}
	void test() {
		int A[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
		int n = sizeof(A) / sizeof(A[0]);
		int result = trap(A, n);
		cout << result << endl;
	}
};
