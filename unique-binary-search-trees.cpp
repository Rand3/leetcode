class Solution {
public:
	int numTrees(int n) {
		// https://oj.leetcode.com/problems/unique-binary-search-trees/
		//
		// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
		// For example, Given n = 3, there are a total of 5 unique BST's. 
		//   1         3     3      2      1
		//    \       /     /      / \      \
		//     3     2     1      1   3      2
		//    /     /       \                 \
		//   2     1         2                 3

		// Solution: DP
		// f(k) := numTrees(k)
		// f(k) = sum (f(i) * f(j)), where i + j + 1 = k, 0 <= i < k
		vector<int> f(n + 1, 0);
		if (n < 2) { return 1; }
		f[0] = 1;
		f[1] = 1;
		for (int k = 2; k <= n; k++) {
			for (int i = 0; i < k; i++) {
				f[k] += f[i] * f[k - i - 1];
			}
		}
		return f[n];
	}
};
