class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
        //
        // Follow up for https://oj.leetcode.com/problems/remove-duplicates-from-sorted-array/
        // Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
        // Do not allocate extra space for another array, you must do this in place with constant memory.
        // What if duplicates are allowed at most twice?
        // For example, Given sorted array A = [1,1,1,2,2,3], Your function should return length = 5, and A is now [1,1,2,2,3].
        
        if (n == 0) { return 0; }
        int read = 1;
        int write = 1;
        int dup = A[0];
        int twice = false;
        while (read != n) {
            if (A[read] != dup) {
                dup = A[read];
                twice = false;
                A[write] = A[read];
                write++;
            }
            else if (!twice) {
                twice = true;
                A[write] = A[read];
                write++;
            }
            read++;
        }
        return write;
    }
};
