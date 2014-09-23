class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // https://oj.leetcode.com/problems/first-missing-positive/
        //
        // Given an unsorted integer array, find the first missing positive integer.
        // For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
        // Your algorithm should run in O(n) time and uses constant space. 
        //

        // Hint: the input array can be modified
        for (int i = 0; i < n; i++) {
            // put A[i] to its expected location, e.g. 3 => A[2]
            while (A[i] >= 1 && A[i] <= n && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
    void test() {
        int A[] = { 1 };
        int expect = 2;
        int result = firstMissingPositive(A, sizeof(A) / sizeof(int));
        if (expect != result) {
            cout << result << ", expect: " << expect << endl;
        }
        int B[] = { 3, 4, -1, 1 };
        expect = 2;
        result = firstMissingPositive(B, sizeof(B) / sizeof(int));
        if (expect != result) {
            cout << result << ", expect: " << expect << endl;
        }
        int C[] = { 1, 1 };
        expect = 2;
        result = firstMissingPositive(C, sizeof(C) / sizeof(int));
        if (expect != result) {
            cout << result << ", expect: " << expect << endl;
        }
    }
};
