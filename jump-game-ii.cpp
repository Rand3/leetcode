class Solution {
public:
	int jump(int A[], int n) {
		// https://oj.leetcode.com/problems/jump-game-ii/
		//
		// Given an array of non-negative integers, you are initially positioned at the first index of the array. 
		// Each element in the array represents your maximum jump length at that position. 
		// Your goal is to reach the last index in the minimum number of jumps. 
		// For example: Given array A = [2,3,1,1,4] 
		// The minimum number of jumps is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

		if (n <= 1) { return 0; }
		vector<int> f(n);
		f[0] = 0;
		int reach = 0;
		for (int i = 0; i < n; i++) {
			if (i > reach) { return -1; }
			int next = i + A[i];
			if (next >= n - 1) {
				return f[i] + 1;
			}
			if (next > reach) {
				for (int j = reach + 1; j <= next; j++) {
					f[j] = f[i] + 1;
				}
				reach = next;
			}
		}
		return -1;
	}
	void test() {
		int A[] = { 2, 3, 1, 1, 4 };
		int result = jump(A, sizeof(A) / sizeof(A[0]));
		cout << result << endl;
	}
};
