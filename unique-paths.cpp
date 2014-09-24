class Solution {
public:
    int uniquePaths(int m, int n) {
        // https://oj.leetcode.com/problems/unique-paths/
        //
        // A robot is located at the top-left corner of a m x n grid (marked 'Start' in 
        // the diagram below). The robot can only move either down or right at any point.
        // The robot is trying to reach the bottom-right corner of the grid (marked 'Finish').
        //
        // How many possible unique paths are there?
        
        // Solution (DP)
        //  f(m,n) = f(m,n-1) + f(m-1,n)
        //  f(m) = f(m) + f(m-1)
        if (m < n) {
            swap(m, n); // ensure n = min(n, m)
        }
        vector<int> f(n+1, 1);
        f[0] = 0;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                f[j] += f[j-1];
            }
        }
        return f[n];
    }
};
