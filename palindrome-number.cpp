class Solution {
public:
	bool isPalindrome(int x) {
		// https://oj.leetcode.com/problems/palindrome-number/
		//
		// Determine whether an integer is a palindrome. Do this without extra space.

		if (x == 0) { return true; }
		if (x < 0) { return false; }
		int mask = 1;
		while (mask <= INT_MAX / 10) {
			mask *= 10;
		}
		while (x / mask == 0) {
		    mask /= 10;
		}
		int mask2 = 1;
		while (mask2 < mask) {
			int high = x / mask % 10;
			int low = x / mask2 % 10;
			if (high != low) { return false; }
			mask /= 10;
			mask2 *= 10;
		}
		return true;
	}
	void test(){
		vector<int> nums = {
			0, -101,
			1, 15, 99, 101, 1221, 1000000001,
			INT_MAX, INT_MAX / 10, 
		};
		for (int x : nums) {
			bool valid = isPalindrome(x);
			cout << x << " : " << valid << endl;
		}
	}
};
