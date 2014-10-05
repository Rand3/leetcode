class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		// https://oj.leetcode.com/problems/combination-sum-ii/
		//
		// Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
		// in C where the candidate numbers sums to T. Each number in C may only be used once in the combination. 
		// Note:
		//  * All numbers (including target) will be positive integers.
		//  * Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <=.. ak).
		//  * The solution set must not contain duplicate combinations.
		// For example, given candidate set [10,1,2,7,6,1,5] and target 8, 
		// A solution set is: [1, 7] [1, 2, 5] [2, 6] [1, 1, 6]

		result.clear();
		path.clear();
		sort(candidates.begin(), candidates.end());
		help(candidates, target, 0);
		return result;
	}
	vector<vector<int>> result;
	vector<int> path;

	void help(vector<int> &candidates, int target, int current) {
		if (target == 0) {
			result.push_back(path);
		}
		else if (target > 0) {
			int prev = -1;
			for (int i = current; i < (int)candidates.size(); i++) {
				int x = candidates[i];
				if (x == prev) { continue; }
				path.push_back(x);
				help(candidates, target - x, i + 1);
				path.pop_back();
				prev = x;
			}
		}
	}
	void test() {
		vector<int> candidates = { 10, 1, 2, 7, 6, 1, 5 };
		int target = 8;
		vector<vector<int>> result = combinationSum2(candidates, target);
		for (auto v : result) {
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
