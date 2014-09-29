class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // https://oj.leetcode.com/problems/surrounded-regions/
        //
        // Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
        // A region is captured by flipping all 'O's into 'X's in that surrounded region.
        // For example, 
        //  X X X X            X X X X
        //  X O O X  becomes:  X X X X
        //  X X O X            X X X X
        //  X O X X            X O X X

        int rows = (int)board.size();
        if (rows == 0) { return; }
        int cols = (int)board[0].size();
        if (cols == 0) { return; }
        // check 4 edges, find any 'O' and their neighbors
        vector<pair<int, int>> edge;
        for (int i = 0; i < cols; i++) {
            check(board, 0, i, edge);
            check(board, rows - 1, i, edge);
        }
        for (int i = 0; i < rows; i++) {
            check(board, i, 0, edge);
            check(board, i, cols - 1, edge);
        }
        // use vector as a FIFO queue
        int begin = 0;
        pair<int, int> delta[] = { { 0, 1 }, { 0, -1 }, { -1, 0 }, { 1, 0 } };
        while (begin != edge.size()) {
            int row = edge[begin].first;
            int col = edge[begin].second;
            begin++;
            for (int i = 0; i < 4; i++) {
                int r2 = row + delta[i].first;
                int c2 = col + delta[i].second;
                if (r2 >= 0 && r2 < rows && c2 >= 0 && c2 < cols) {
                    check(board, r2, c2, edge);
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                board[i][j] = 'X';
            }
        }
        for (auto e : edge) {
            board[e.first][e.second] = 'O';
        }
    }
    void check(vector<vector<char>> &board, int row, int col, vector<pair<int, int>> &edge) {
        if (board[row][col] == 'O') {
            board[row][col] = 'X';
            edge.push_back(pair<int, int>(row, col));
        }
    }
    void test() {
        vector<string> matrix = {
            "XXXX",
            "XOOX",
            "XXOX",
            "XOXX"
        };
        vector<vector<char>> board;
        for (string s : matrix) {
            vector<char> v(s.begin(), s.end());
            board.push_back(v);
        }
        solve(board);
    }
};
