class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		// https://oj.leetcode.com/problems/rotate-image/
		//
		// You are given an n x n 2D matrix representing an image.
		// Rotate the image by 90 degrees (clockwise) in-place.

		int size = (int)matrix.size();
		int row = size / 2;
		int col = (size + 1) / 2;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				int di = size - 1 - i;
				int dj = size - 1 - j;
				int temp = matrix[i][j];
				matrix[i][j] = matrix[dj][i];
				matrix[dj][i] = matrix[di][dj];
				matrix[di][dj] = matrix[j][di];
				matrix[j][di] = temp;
			}
		}
	}
};
