class Solution {
public:
    vector<vector<int>> generate(int rows) {
        // https://oj.leetcode.com/problems/pascals-triangle/
        //
        // Given numRows, generate the first numRows of Pascal's triangle.
        // For example, given numRows = 5, Return
        // [
        //     [1],
        //    [1,1],
        //   [1,2,1],
        //  [1,3,3,1],
        // [1,4,6,4,1]
        // ]
        vector<vector<int>> result(rows);
        if (rows == 0) { return result; }
        result[0].push_back(1);
        for (int i = 1; i < rows; i++) {
            result[i].push_back(1);
            for (int j = 1; j < i; j++) {
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};
