class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int> &num) {
		// https://oj.leetcode.com/problems/permutations-ii/
		//
		// Given a collection of numbers that might contain duplicates, 
		// return all possible unique permutations (i.e. re-arrangement). 
		// For example, Given [1,1,2], Returns [1,1,2], [1,2,1], [2,1,1]. 

		sort(num.begin(), num.end());
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
		int size = (int)num.size() - step;
		if (size == 0) {
			result.push_back(path);
			return;
		}
		int prev = q.front() - 1;
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop_front();
			if (i == 0 || x != prev) {
				path[step] = x;
				help(num, step + 1);
			}
			q.push_back(x);
			prev = x;
		}
	}
	void test() {
		vector<int> num = { 1, 1, 2, 2, 2 };
		vector<vector<int>> result = permuteUnique(num);
		for (auto v : result) {
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
