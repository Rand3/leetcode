class Solution {
public:
	bool exist(vector<vector<char>> &board, string word) {
		// https://oj.leetcode.com/problems/word-search/
		//
		// Given a 2D board and a word, find if the word exists in the grid.
		// The word can be constructed from letters of sequentially adjacent 
		// cell, where "adjacent" cells are those horizontally or vertically 
		// neighboring. The same letter cell may not be used more than once.
		// For example, Given board = [
		//   ["ABCE"],
		//   ["SFCS"],
		//   ["ADEE"]]
		// word = "ABCCED", returns true,
		// word = "SEE", returns true,
		// word = "ABCB", returns false.
		vector<pair<int, int>> path(word.length());
		for (int i = 0; i < (int)board.size(); i++) {
			for (int j = 0; j < (int)board[0].size(); j++) {
				if (help(board, word, i, j, 0, path)) {
					return true;
				}
			}
		}
		return false;
	}
	bool help(vector<vector<char>> &board, string &word, int i, int j, int index, vector<pair<int, int>> &path) {
		static pair<int, int> choices[] = {
				{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
		};
		bool found = false;
		if (board[i][j] == word[index]) {
			if (index + 1 == (int)word.length()) {
				return true;
			}
			path[index].first = i;
			path[index].second = j;
			board[i][j] = '\0';
			for (auto choice : choices) {
				int m = i + choice.first;
				int n = j + choice.second;
				if (m >= 0 && m < (int)board.size() && n >= 0 && n < (int)board[0].size()) {
					if (help(board, word, m, n, index + 1, path)) {
						found = true;
						break;
					}
				}
			}
			board[i][j] = word[index];
		}
		return found;
	}
	void test() {
		vector<vector<char>> simple = { { 'a' } };
		string word = "a";
		bool expected = true;
		if (exist(simple, word) != expected) {
			cout << "ERROR" << endl;
		}
		vector<vector<char>> board = {
				{ 'A', 'B', 'C', 'E' },
				{ 'S', 'F', 'C', 'S' },
				{ 'A', 'D', 'E', 'E' }
		};
		struct TestCases {
			string s;
			bool result;
		};
		TestCases tests[] = {
				{ "SEE", true },
				{ "ABCCED", true },
				{ "ABCB", false }
		};
		for (auto test : tests) {
			bool result = exist(board, test.s);
			if (result != test.result) {
				cout << "ERROR: " << test.s << " returns " << result << endl;
			}
		}
	}
};
