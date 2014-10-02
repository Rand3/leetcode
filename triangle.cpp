class Solution {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		// https://oj.leetcode.com/problems/triangle/
		//
		// Given a triangle, find the minimum path sum from top to bottom. 
		// Each step you may move to adjacent numbers on the row below.
		// For example, given the following triangle
		// [
		//     [2],
		//    [3,4],
		//   [6,5,7],
		//  [4,1,8,3]
		// ]
		// The minimum path sum from top to bottom is 11 (2 + 3 + 5 + 1).
		// Do this using only O(n) extra space, where n is the rows.

		// f(k) := min sum to k-th number, in any given row
		// f(k) = min(f(k-1), f(k)) + triangle[row][k]
		int size = triangle.size();
		if (size == 0) { return 0; }
		vector<int> f(size + 1, INT_MAX);
		f[1] = triangle[0][0];
		int result = f[1];
		for (int row = 2; row <= size; row++) {
			result = INT_MAX;
			for (int k = row; k >= 1; k--) { // reverse to not overwrite data early
				f[k] = min(f[k - 1], f[k]) + triangle[row - 1][k - 1];
				result = min(result, f[k]);
			}
		}
		return result;
	}
	void test() {
		vector<vector<int>> t = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
		int result = minimumTotal(t);
		cout << result << endl;
	}
};
