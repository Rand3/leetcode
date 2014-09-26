class Solution {
public:
	vector<vector<int>> subsets(vector<int> &S) {
		// https://oj.leetcode.com/problems/subsets/
		//
		// Given a set of distinct integers, S, return all possible subsets. 
		//  * Elements in a subset must be in non-descending order
		//  * The solution set must not contain duplicate subsets
		// For example, if S=[1,2,3], a solution is
		//  [ [], [3],[1],[2], [1,2,3], [1,3], [2,3], [1,2] ]

		// Solution: tree travesal
		vector<vector<int>> result;
		sort(S.begin(), S.end());
		vector<int> path;
		help(S, 0, path, result);
		return result;
	}
	void help(vector<int> &S, int start, vector<int> &path, vector<vector<int>> &result) {
		result.push_back(path);
		int size = (int)S.size();
		for (int i = start; i < size; i++) {
			path.push_back(S[i]);			
			help(S, i + 1, path, result);
			path.pop_back();
		}
	}
	void test() {
		vector<int> S = { 2, 1, 3 };
		vector<vector<int>> result = subsets(S);
	}
};
