class Solution {
public:
	bool canJump(int A[], int n) {
		// https://oj.leetcode.com/problems/jump-game/
		//
		// Given an array of non-negative integers, you are initially positioned at the first index of the array.
		// Each element in the array represents your maximum jump length at that position.
		// Determine if you are able to reach the last index.
		// For example: A = [2,3,1,1,4], return true. A = [3,2,1,0,4], return false. 

		int reach = 0;
		for (int i = 0; i < n; i++) {
			if (i > reach) {
				return false;
			}
			int next = i + A[i];
			if (next >= n - 1) {
				return true;
			}
			reach = max(reach, next);
		}
		return false;
	}
};
