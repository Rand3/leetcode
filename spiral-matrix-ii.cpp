class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		// https://oj.leetcode.com/problems/spiral-matrix-ii/
		//
		// Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
		// For example, Given n = 3, You should return the following matrix:
		// [ [ 1, 2, 3 ],
		//   [ 8, 9, 4 ],
		//   [ 7, 6, 5 ] ]

		vector<vector<int>> r(n, vector<int>(n));
		int half = n / 2;
		int len = n - 1;
		int num = 1;
		for (int k = 0; k < half; k++) {
			int x = k;
			int y = k;
			for (int i = 0; i < len; i++) {
				r[x][y++] = num++;
			}
			for (int i = 0; i < len; i++) {
				r[x++][y] = num++;
			}
			for (int i = 0; i < len; i++) {
				r[x][y--] = num++;
			}
			for (int i = 0; i < len; i++) {
				r[x--][y] = num++;
			}
			len -= 2;
		}
		if (n % 2 != 0) {
			r[half][half] = num;
		}
		return r;
	}
	void test() {
		generateMatrix(3);
	}
};
