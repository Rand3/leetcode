class Solution {
public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
		// https://oj.leetcode.com/problems/combination-sum/
		//
		// Given a set of candidate numbers (C) and a target number (T), find all unique combinations 
		// in C where the candidate numbers sums to T. The same repeated number may be chosen from C 
		// unlimited number of times. 
		// Note:
		//  * All numbers (including target) will be positive integers.
		//  * Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <=.. ak).
		//  * The solution set must not contain duplicate combinations.
		// For example, given candidate set 2,3,6,7 and target 7, 
		// A solution set is: [7] [2, 2, 3]

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
			for (int i = current; i < (int)candidates.size(); i++) {
				int x = candidates[i];
				path.push_back(x);
				help(candidates, target - x, i);
				path.pop_back();
			}
		}
	}
	void test() {
		vector<int> candidates = { 2, 3, 6, 7 };
		int target = 7;
		vector<vector<int>> result = combinationSum(candidates, target);
		for (auto v : result) {
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
