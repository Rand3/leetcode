class Solution {
public:
    vector<int> getRow(int row) {
        // https://oj.leetcode.com/problems/pascals-triangle-ii/
        //
        // Given an index k, return the kth row of the Pascal's triangle.
        // For example, given k = 3, Return [1,3,3,1].
        // Use O(k) extra space
        
        vector<int> result(row+1, 0);
        result[0] = 1;
        for (int i = 1; i <= row; i++) {
            for (int j = i; j > 0; j--) {
                result[j] += result[j-1];
            }
        }
        return result;
    }
};
