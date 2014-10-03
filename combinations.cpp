class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		// https://oj.leetcode.com/problems/combinations/
		//
		// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
		// For example, If n = 4 and k = 2, a solution is:
		// [  [2,4],  [3,4],  [2,3],  [1,2],  [1,3],  [1,4]  ]

		result.clear();
		path.clear();
		help(n, k, 1);
		return result;
	}
	vector<vector<int>> result;
	vector<int> path;
	void help(int n, int step, int start) {
		if (step == 0) {
			result.push_back(path);
			return;
		}
		int prev = (start == 1 ? 0 : path.back());
		for (int i = prev + 1; i <= n; i++) {
			path.push_back(i);
			help(n, step - 1, start + 1);
			path.pop_back();
		}
	}
	void test() {
		vector<vector<int>> result = combine(4, 2);
		for (auto v : result) {
			for (int n : v) {
				cout << n << ' ';
			}
			cout << endl;
		}
	}
};
