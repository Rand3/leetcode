class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // https://oj.leetcode.com/problems/merge-sorted-array/
        //
        // Given two sorted integer arrays A and B, merge B into A as one sorted array. 
        // Note: You may assume that A has enough space (size that is greater or equal to m + n).
        // The number of elements initialized in A and B are m and n respectively.
        
        int k = m + n - 1;
        m--;
        n--;
        while (k >= 0) {
            int x = (m >= 0 ? A[m] : INT_MIN);
            int y = (n >= 0 ? B[n] : INT_MIN);
            if (x > y) {
                A[k] = x;
                m--;
            }
            else {
                A[k] = y;
                n--;
            }
            k--;
        }
    }
};
