class Solution {
public:
	int maxSubArray(int A[], int n) {
		// https://oj.leetcode.com/problems/maximum-subarray/
		//
		// Find the contiguous subarray within an array (containing at least one number) which has the largest sum. 
		// For example, given the array [-2,1,-3,4,-1,2,1,-5,4]
		// the contiguous subarray [4,-1,2,1] has the largest sum = 6. 

		int result = A[0];
		int total = result;
		for (int i = 1; i < n; i++) {
			if (total <= 0) {
				total = A[i];
			}
			else {
				total += A[i];
			}
			result = max(result, total);
		}
		return result;
	}
	void test() {
		int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
		int maxSub = maxSubArray(A, sizeof(A) / sizeof(int));
		cout << maxSub << endl;
	}
};
