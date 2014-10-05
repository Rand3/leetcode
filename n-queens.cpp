class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		// https://oj.leetcode.com/problems/n-queens/
		//
		// The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
		// such that no two queens attack each other.
		// Given an integer n, return all distinct solutions to the n-queens puzzle. 
		// Each solution contains a distinct board configuration of the n-queens' placement, 
		// where 'Q' and '.' both indicate a queen and an empty space respectively.

		this->n = n;
		path = vector<int>(n); // col position of queens in each row
		result.clear();
		help(0);
		return result;
	}
	int n;
	vector<int> path;
	vector<vector<string>> result;
	void help(int step) {
		if (step == n) {
			addBoard();
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
	void addBoard() {
		string row(n, '.');
		vector<string> board;
		for (int i = 0; i < n; i++) {
			int j = path[i];
			row[j] = 'Q';
			board.push_back(row);
			row[j] = '.';
		}
		result.push_back(board);
	}
	void test() {
		vector<vector<string>> result = solveNQueens(8);
		for (auto v : result) {
			for (string s : v) {
				cout << s << endl;
			}
			cout << endl;
		}
		cout << "total: " << result.size() << endl;
	}
};
