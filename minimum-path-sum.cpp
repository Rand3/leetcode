class Solution {
public:
	int minPathSum(vector<vector<int>> &grid) {
		// https://oj.leetcode.com/problems/minimum-path-sum/
		//
		// Given a m x n grid filled with non-negative numbers, find a path from top 
		// left to bottom right which minimizes the sum of all numbers along its path.
		// Note: You can only move either down or right at any point in time.

		// Solution: DP
		// f(i,j) := minPathSum(grid[first i row, first j col])
		// f(i,j) = min(f[i-1,j], f[i,j-1]) + grid[i,j]
		// f(j) = min(f(j-1), f(j)) + grid[i,j]
		int rows = grid.size();
		int cols = grid[0].size();
		vector<int> f(cols + 1, INT_MAX);
		f[1] = 0;
		for (int i = 0; i < rows; i++) {
			for (int j = 1; j <= cols; j++) {
				f[j] = min(f[j - 1], f[j]) + grid[i][j - 1];
			}
		}
		return f[cols];
	}
	void test() {
		vector<vector<int>> grid = {
			{ 1, 2, 5 },
			{ 3, 2, 1 }
		};
		int path = minPathSum(grid);
	}
};
