class Solution {
public:
    int singleNumber(int A[], int n) {
        // https://oj.leetcode.com/problems/single-number/
        //
        // Given an array of integers, every element appears twice except
        // for one. Find that single one in O(N) time and O(1) space.
        
        if (n == 0) { return 0; }
        //  a  0 0 1 1, a xor b = b xor a
        //  b  0 1 0 1, (a xor b) xor c = a xor (b xor c)
        // xor 0 1 1 0,
        // for any element that appears twice, xor will get 0.
        // for any single element, xor will get the original number.
        //
        int result = A[0];
        for (int i = 1; i < n; i++) {
            result ^= A[i];
        }
        return result;
    }
};
