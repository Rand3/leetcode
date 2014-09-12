class Solution {
public:
	// https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
	//
	// given an array, the median is the number in the array that is
	// bigger than half of all numbers, and smaller than the other half
	//
	// if the total number is odd, the median is unique; if the total
	// is even, the median is the average of the two middle numbers
	//
	// For example:
	//     [1, 2, 5], median = A[1] = 2,
	//     [1, 2, 5, 10], median = (A1 + A2) / 2 = 3.5
	//
	// There are two sorted arrays A and B of size m and n respectively. 
	// Find the median of the two sorted arrays. The overall run time 
	// complexity should be O(log (m+n)).
	//
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// 1 2 3 4 5:   median index = 3, 3
		// 1 2 3 4 5 6: median index = 3, 4
		int i = (m + n + 1) / 2;
		int j = (m + n + 2) / 2;
		int mid1 = findKth(A, m, B, n, i);
		int mid2 = findKth(A, m, B, n, j);
		return 0.5 * (mid1 + mid2);
	}
	int findKth(int A[], int m, int B[], int n, int k) {
		//
		// http://leetcode.com/2011/01/find-k-th-smallest-element-in-union-of.html
		//
		// Get k'th element in the merge of two sorted arrays. 1 <= k <= m+n
		//
		// Compare A[k/2] and B[k/2].
		// If A[k/2] < B[k/2], it means these A[1] to A[k/2] elements are part of first k elements.
		// Now, the kth element can be in A[k/2 + 1] to A[k] or B[1] to B[k/2].
		// Hence, we reduced the problem to half of its original size.
		// 
		while (true) {
			int half = k / 2;
			int i = min(m, half);
			int j = min(n, half);
			if (m == 0) {
				return B[k - 1];
			}
			if (n == 0) {
				return A[k - 1];
			}
			if (k == 1) {
				return min(A[0], B[0]);
			}
			// now both i and j > 0, and i + j <= k
			if (A[i - 1] < B[j - 1]) {
				// case 1: i + j < k
				//   we need more numbers. They have to come from the group with smaller numbers,
				//   i.e. A[]. That also means A[0..i-1] are in range of 1..k. Remove them
				// case 2: i + j = k
				//   it is possible that is all, maybe B[j-1] is kth number. we do not know. but
				//   we do know that A[i-1] cannot be k'th, which again means that A[0..i-1] are
				//   in range of 1..k. Remove them too

				// return findKth(A + i, m - i, B, n, k - i);
				A += i;
				m -= i;
				k -= i;
			}
			else {
				// return findKth(A, m, B + j, n - j, k - j);
				B += j;
				n -= j;
				k -= j;
			}
		}
	}
	void test() {
		int A[] = { 1, 5 };
		int B[] = { 2, 10 };
		double median = findMedianSortedArrays(A, 2, B, 2);
		cout << median << endl;
	}
};
