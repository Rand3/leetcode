class Solution {
public:
	void solveSudoku(vector<vector<char>> &board) {
		// https://oj.leetcode.com/problems/sudoku-solver/
		//
		// Sudoku is a 9*9 matrix, with each cell filled with number 1-9.
		// Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
		//   1) Each row must have the numbers 1-9 occuring just once.
		//   2) Each column must have the numbers 1-9 occuring just once.
		//   3) And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
		// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
		// Write a program to solve a Sudoku puzzle by filling the empty cells.
		// You may assume that there will be only one unique solution. 

		help(board, 0);
	}
	bool help(vector<vector<char>> &board, int k) {
		int row, col;
		do {
			if (k == 81) { return true; }
			row = k / 9;
			col = k % 9;
			k++;
		} while (board[row][col] != '.');
		for (char c = '1'; c <= '9'; c++) {
			board[row][col] = c;
			if (validate(board, row, col) && help(board, k)) {
				return true;
			}
		}
		board[row][col] = '.';
		return false;
	}
	bool validate(vector<vector<char>> &board, int row, int col) {
		int x = board[row][col];
		for (int i = 0; i < 9; i++) {
			if (i != row && board[i][col] == x) { return false; }
			if (i != col && board[row][i] == x) { return false; }
		}
		int m = row / 3 * 3;
		int n = col / 3 * 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[m + i][n + j] == x) {
					if (m + i != row || n + j != col) { return false; }
				}
			}
		}
		return true;
	}
};
