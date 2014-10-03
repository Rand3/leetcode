class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
        //
        // Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
        // Do not allocate extra space for another array, you must do this in place with constant memory.
        // For example, Given input array A = [1,1,2], Your function should return length = 2, and A is now [1,2].
        
        if (n == 0) { return 0; }
        int read = 1;
        int write = 1;
        int dup = A[0];
        while (read < n) {
            if (A[read] != dup) {
                A[write] = A[read];
                write++;
                dup = A[read];
            }
            read++;
        }
        return write;
    }
};
