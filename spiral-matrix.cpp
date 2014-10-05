class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		// https://oj.leetcode.com/problems/spiral-matrix/
		//
		// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
		// For example, Given the following matrix: 
		// [ [ 1, 2, 3 ],
		//   [ 4, 5, 6 ],
		//   [ 7, 8, 9 ] ]
		// You should return [1,2,3,6,9,8,7,4,5]. 

		vector<int> result;
		int rows = (int)matrix.size();
		if (rows == 0) { return result; }
		int cols = (int)matrix[0].size();
		if (cols == 0) { return result; }
		result = vector<int>(rows * cols);
		vector<int>::iterator it = result.begin();
		int half = min(rows, cols) / 2;
		rows--;
		cols--;
		for (int k = 0; k < half; k++) {
			int x = k;
			int y = k;
			int i;
			for (i = 0; i < cols; i++) {
				(*it++) = matrix[x][y++];
			}
			for (i = 0; i < rows; i++) {
				(*it++) = matrix[x++][y];
			}
			for (i = 0; i < cols; i++) {
				(*it++) = matrix[x][y--];
			}
			for (i = 0; i < rows; i++) {
				(*it++) = matrix[x--][y];
			}
			rows -= 2;
			cols -= 2;
		}
		if (min(rows, cols) % 2 == 0) {
			int x = half;
			int y = half;
			int i;
			if (cols >= rows) {
				for (i = 0; i <= cols; i++){
					(*it++) = matrix[x][y++];
				}
			}
			else {
				for (i = 0; i <= rows; i++) {
					(*it++) = matrix[x++][y];
				}
			}
		}
		return result;
	}
	void test() {
		vector<vector<int>> matrix = { { 1 }, { 2 } };
		spiralOrder(matrix);
	}
};
