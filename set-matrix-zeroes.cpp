class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        // https://oj.leetcode.com/problems/set-matrix-zeroes/
        //
        // Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
        // Do it in place and use O(1) space.

        // Solution: use a row and a col in matrix itself to save data to be cleared
        int rows = (int)matrix.size();
        if (rows == 0) { return; }
        int cols = (int)matrix[0].size();
        if (cols == 0) { return; }
        bool found = false;
        int save_row;
        int save_col;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    if (!found) {
                        found = true;
                        save_row = i;
                        save_col = j;
                    }
                    else {
                        matrix[save_row][j] = 0;
                        matrix[i][save_col] = 0;
                    }
                }
            }
        }
        if (!found) { return; } // IMPORTANT: do not miss this error condition
        for (int i = 0; i < rows; i++) {
            if (i == save_row) { continue; } // IMPORTANT: do not clear 'saved' row or else we'll get all zero
            if (matrix[i][save_col] == 0) {
                for (int j = 0; j < cols; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < cols; j++) {
            if (j == save_col) { continue; }
            if (matrix[save_row][j] == 0) {
                for (int i = 0; i < rows; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            matrix[i][save_col] = 0;
        }
        for (int j = 0; j < cols; j++) {
            matrix[save_row][j] = 0;
        }
    }
    void test() {
        vector<vector<int>> matrix = { 
            { 0, 0, 0, 5 }, 
            { 4, 3, 1, 4 }, 
            { 0, 1, 1, 4 }, 
            { 1, 2, 1, 3 }, 
            { 0, 0, 1, 1 }
        };
        setZeroes(matrix);
    }
};
