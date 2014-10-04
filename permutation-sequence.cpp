class Solution {
public:
	string getPermutation(int n, int k) {
		// https://oj.leetcode.com/problems/permutation-sequence/
		//
		// The set [1,2,3,…,n] contains a total of n! unique permutations.
		// By listing and labeling all of the permutations in order,
		// We get the following sequence (ie, for n = 3):
		//  1. "123"
		//  2. "132"
		//  3. "213"
		//  4. "231"
		//  5. "312"
		//  6. "321"
		// Given n and k, return the kth permutation sequence.
		// Note: Given n will be between 1 and 9 inclusive.
		// Note: permutations = re-arrange

		// n = 1: 1
		// n = 2: 12, 21
		// n = 3: 3*2=6
		// n = 4: 4*6=24
		//  1..6 = 1, 7..12 = 2, 13..18 = 3, 19..24 = 4
		int bang = 1;
		vector<int> nums;
		for (int i = 1; i <= n; i++) {
			bang *= i;
			nums.push_back(i);
		}
		k--; // switch to 0-based index
		if (k >= bang || k < 0) { return ""; }
		string result;
		for (int i = n; i >= 1; i--) {
			bang /= i;
			int x = k / bang;
			k %= bang;
			result.push_back('0' + nums[x]);
			nums.erase(nums.begin() + x);
		}
		return result;
	}
	void test() {
		int n = 4;
		for (int k = 0; k < 26; k++) {
			cout << getPermutation(n, k) << endl;
		}
	}
};
