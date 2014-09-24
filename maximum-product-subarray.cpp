class Solution {
public:
    int maxProduct(int A[], int n) {
        // https://oj.leetcode.com/problems/maximum-product-subarray/
        //
        // Find the contiguous subarray within an array (containing at 
        // least one number) which has the largest product.
        // For example, given the array [2,3,-2,4], the contiguous subarray
        // [2,3] has the largest product = 6.

        // [-1, 2, 3, -2, 4, -1, 5, -2, 0]
        //
        // 0 : split array to independent sub-arrays
        // unless there is only one number and it is negative, the result will
        // always be positive.
        // neg: pause for a while, until next neg appears.
        //  step 1. count neg. if even, the max is production of all numbers
        //  step 2. if neg number is odd, the result must be either:
        //     [pos..pos] first neg [other pos or neg numbers], 
        //     or: [other pos or neg numbers] last neg [pos..pos]
        // notice that the best result always starts from the edge of the array
        // http://leetcodesolution.blogspot.com/2014/09/leetcode-maximum-product-subarray.html
        int result = INT_MIN;
        int x = 1;
        for (int i = 0; i < n; i++) {
            x *= A[i];
            result = max(result, x);
            if (A[i] == 0) {
                x = 1;
            }
        }
        x = 1;
        for (int i = n - 1; i >= 0; i--) {
            x *= A[i];
            result = max(result, x);
            if (A[i] == 0) {
                x = 1;
            }
        }
        return result;
    }
};
