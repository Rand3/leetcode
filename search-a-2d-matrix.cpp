class Solution {
public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		// https://oj.leetcode.com/problems/search-a-2d-matrix/
		//
		// Searches for a value in an m x n matrix. This matrix has the following properties:
		//  * Integers in each row are sorted from left to right.
		//  * The first integer of each row is greater than the last integer of the previous row.
		// For example,  Consider the following matrix:
		// [[1,   3,  5,  7],
		//  [10, 11, 16, 20],
		//  [23, 30, 34, 50]]
		// Given target = 3, return true.

		int rows = (int)matrix.size();
		int cols = (int)matrix[0].size();
		int left = 0;
		int right = rows * cols - 1;
		while (left <= right) {
			int middle = left + (right - left) / 2;
			int i = middle / cols;
			int j = middle % cols;
			int x = matrix[i][j];
			if (x == target) { return true; }
			if (x > target) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
		return false;
	}
};
