class Solution {
public:
	int totalNQueens(int n) {
		// https://oj.leetcode.com/problems/n-queens-ii/
		//
		// Follow up for https://oj.leetcode.com/problems/n-queens/
		// The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
		// such that no two queens attack each other.
		// Now, instead outputting board configurations, return the total number of distinct solutions.

		this->n = n;
		path = vector<int>(n); // col position of queens in each row
		result = 0;
		help(0);
		return result;
	}
	int n;
	vector<int> path;
	int result;
	void help(int step) {
		if (step == n) {
			result++;
			return;
		}
		for (int i = 0; i < n; i++) {
			path[step] = i;
			if (isValid(step)) {
				help(step + 1);
			}
		}
	}
	bool isValid(int step) {
		int my = path[step];
		for (int i = 0; i < step; i++) {
			int you = path[i];
			if (my == you || step - i == abs(my - you)) {
				return false;
			}
		}
		return true;
	}
	void test() {
		int result = totalNQueens(8);
		cout << "total: " << result << endl;
	}
};
