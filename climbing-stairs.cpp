class Solution {
public:
	int climbStairs(int n) {
		// https://oj.leetcode.com/problems/climbing-stairs/
		//
		// You are climbing a stair case. It takes n steps to reach to the top.
		// Each time you can either climb 1 or 2 steps. In how many distinct ways 
		// can you climb to the top? 

		// Solution: DP
		// f(k) := climbStairs(k)
		// f(k) = f(k-1) + f(k-2)
		// k = 0, 1, 2, 3
		//  => 1, 1, 2, 3
		int f1 = 1;
		int f2 = 1;
		if (n < 2) { return 1; }
		int f;
		for (int i = 2; i <= n; i++) {
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		return f;
	}
};
