class Solution {
public:
	void sortColors(int A[], int n) {
		// https://oj.leetcode.com/problems/sort-colors/
		//
		// Given an array with n objects colored red, white or blue, sort them so that objects of 
		// the same color are adjacent, with the colors in the order red, white and blue.
		// Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue.

		// only 3 type to sort
		int i = 0;
		int bottom = 0;
		int top = n - 1;
		while (i <= top) {
			if (A[i] == 0) {
				swap(A[i], A[bottom]);
				bottom++;
				i++;
			}
			else if (A[i] == 2) {
				swap(A[i], A[top]);
				top--;
			}
			else {
				i++;
			}
		}
	}
};
