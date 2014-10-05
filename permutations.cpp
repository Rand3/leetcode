class Solution {
public:
	vector<vector<int>> permute(vector<int> &num) {
		// https://oj.leetcode.com/problems/permutations/
		//
		// Given a collection of numbers, return all possible permutations. 
		// For example, [1,2,3] have the following permutations:
		// [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
		// Note: assume there is no duplicate in input numbers. 
		// permutation = re-arrangement

		result.clear();
		path = vector<int>(num);
		q.clear();
		q.insert(q.begin(), num.begin(), num.end());
		help(num, 0);
		return result;
	}
	vector<vector<int>> result;
	vector<int> path;
	deque<int> q;

	void help(vector<int> &num, int step) {
		if (step == (int)num.size()) {
			result.push_back(path);
			return;
		}
		for (int i = 0; i < (int)q.size(); i++) {
			int x = q.front();
			q.pop_front();
			path[step] = x;
			help(num, step + 1);
			q.push_back(x);
		}
	}
	void test() {
		vector<int> num = { 1, 2, 3 };
		permute(num);
	}
};
