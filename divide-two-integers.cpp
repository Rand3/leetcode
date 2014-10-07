class Solution {
public:
	int divide(int dividend, int divisor) {
		// https://oj.leetcode.com/problems/divide-two-integers/
		//
		// Divide two integers without using multiplication, division and mod operator.

		// The idea is to left-shift divisor (multiple by 2) until it reaches dividend
		// For example, 54 / 5 = 10, 54 ~= (8 + 2) * 5
		//
		if (divisor == 0 ||
			(dividend == INT_MIN && divisor == -1)) {
			// overflow
			return INT_MAX;
		}
		bool neg = (dividend < 0) ^ (divisor < 0);
		utype u_dividend = Abs(dividend);
		utype u_divisor = Abs(divisor);
		utype mask = 1;
		while (u_divisor < u_dividend) {
			u_divisor <<= 1;
			mask <<= 1;
		}
		int result = 0;
		while (mask != 0) {
			if (u_dividend >= u_divisor) {
				u_dividend -= u_divisor;
				result += mask;
			}
			u_divisor >>= 1;
			mask >>= 1;
		}
		return neg ? (-1 * result) : result;
	}
	typedef unsigned int utype;
	static const utype ABS_INT_MIN = ((utype)INT_MAX) + 1;
	utype Abs(int x) {
		if (x > 0) { return x; }
		else {
			return (x == INT_MIN) ? ABS_INT_MIN : -x;
		}
	}
	void test() {
		vector<pair<int, int>> tests = {
				{ 54, 5 },
				{ 5, 0 },
				{ INT_MAX, 1 },
				{ INT_MAX, -1 },
				{ INT_MIN, 1 },
				{ INT_MIN, -1 },
				{ INT_MAX, INT_MAX },
				{ INT_MAX, INT_MIN },
				{ INT_MIN, INT_MIN },
				{ INT_MIN, INT_MAX },
				{ INT_MAX, INT_MAX / 2 - 5 },
				{ INT_MAX, INT_MAX / 2 + 5 },
		};
		for (auto test : tests) {
			int a = test.first;
			int b = test.second;
			int result = divide(a, b);
			cout << a << " / " << b << " = " << result << endl;
		}
	}
};
