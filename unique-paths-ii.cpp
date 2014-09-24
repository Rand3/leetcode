class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid) {
        // https://oj.leetcode.com/problems/unique-paths-ii/
        //
        // Follow up for "Unique Paths" https://oj.leetcode.com/problems/unique-paths/
        //
        // A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
        // the diagram below). The robot can only move either down or right at any point.
        // The robot is trying to reach the bottom-right corner of the grid (marked 'Finish').
        //
        // The grid is marked as 0 for empty space and 1 for an obstacle. The robot cannot
        // move across the obstacle cells. How many unique paths would there be?
        //
        // For example, the total number of unique paths is 2 for the following grid,
        // [ [0,0,0],
        //   [0,1,0],
        //   [0,0,0] ]

        // Solution (DP)
        //  f(m,n) = f(m,n-1) + f(m-1,n), if there is no obstacle
        //  f(m) = f(m) + f(m-1)
        int rows = (int)grid.size();
        if (rows == 0) { return 0; }
        int cols = (int)grid[0].size();
        if (cols == 0) { return 0; }
        vector<int> f(cols+1, 0);
        f[1] = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (grid[i][j-1] == 1) {
                    f[j] = 0;
                }
                else {
                    f[j] += f[j-1];
                }
            }
        }
        return f[cols];
    }
};
