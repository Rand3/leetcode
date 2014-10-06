class Solution {
public:
	int reverse(int x) {
		// https://oj.leetcode.com/problems/reverse-integer/
		//
		// Reverse digits of an integer.
		// Example1: x = 123, return 321
		// Example2: x = -123, return -321 
		// If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
		// Did you notice that the reversed integer might overflow?
		
		// return INT_MAX or INT_MIN if overflow
		bool neg = (x < 0);
		if (x == 0) { return 0; }
		unsigned u = (x > 0 ? x : -x);
		unsigned r = 0;
		while (u > 0) {
			unsigned d = u % 10;
			u /= 10;
			r = r * 10 + d;
		}
		if (r >= INT_MAX) { return INT_MAX; }
		return neg ? -r : r;
	}
};
