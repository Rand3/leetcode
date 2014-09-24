class Solution {
public:
	int singleNumber(int A[], int n) {
	    // https://oj.leetcode.com/problems/single-number-ii/
	    //
	    // Given an array of integers, every element appears three times except for one. 
	    // Find that single one. Time O(n) and space O(1).
		return singleNumber(A, n, 3);
	}
	
	int singleNumber(int A[], int n, int k) {
	    // Given an array of integers, every element appears k times except for one
	    
	    // for each bit (0..31), add bits from all numbers together, and then mod by k
	    // for those appears k times.
	    //    (0*k) % k = 0, (1*k) % k = 0
	    // for the one abnormal,
	    //    (0*??) % k = 0, (1*??) % k = ??
	    int bit_width = sizeof(int) * 8;
	    int mask = 1;
	    int result = 0;
	    for (int i = 0; i < bit_width; i++) {
	        int total = 0;
	        for (int j = 0; j < n; j++) {
	            int bit = (A[j] & mask) >> i;
	            total += bit;
	        }
	        if (total % k != 0) {
	            result += mask;
	        }
	        mask <<= 1;
	    }
	    return result;
	}
};
