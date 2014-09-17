class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // https://oj.leetcode.com/problems/valid-sudoku/
        //
        // Sudoku is a 9*9 matrix, with each cell filled with number 1-9.
        // Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx
        //   1) Each row must have the numbers 1-9 occuring just once.
        //   2) Each column must have the numbers 1-9 occuring just once.
        //   3) And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
        // The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
        // NOTE: A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
        //
        for (int i = 0; i < 9; i++) {
            unordered_set<char> row, col, box;
            for (int j = 0; j < 9; j++) {
                // row i, col 1..9
                char c = board[i][j];
                if (c != '.') {
                    if (row.count(c) != 0) {
                        return false;
                    }
                    row.insert(c);
                }
                // col i, row 1..9
                c = board[j][i];
                if (c != '.') {
                    if (col.count(c) != 0) {
                        return false;
                    }
                    col.insert(c);
                }
                // box i, cel 1..9
                int top = i / 3 * 3 + j / 3;
                int left = i % 3 * 3 + j % 3;
                c = board[top][left];
                if (c != '.') {
                    if (box.count(c) != 0) {
                        return false;
                    }
                    box.insert(c);
                }
            }
        }
        return true;
    }
};
