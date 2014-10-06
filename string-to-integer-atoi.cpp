class Solution {
public:
	int atoi(const char *str) {
		// https://oj.leetcode.com/problems/string-to-integer-atoi/
		//
		// Implement atoi to convert a string to an integer.
		// Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
		// Notes: It is intended for this problem to be specified vaguely(ie, no given input specs).You are responsible to gather all the input requirements up front.
		// Requirements for atoi :
		// The function first discards as many whitespace characters as necessary until the first non - whitespace character is found.Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
		// The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
		// If the first sequence of non - whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
		// If no valid conversion could be performed, a zero value is returned.If the correct value is out of the range of representable values, INT_MAX(2147483647) or INT_MIN(-2147483648) is returned.

		// input := space* [+|-] digit+ non-digit
		bool neg = false;
		while (*str == ' ') {
			str++;
		}
		if (*str == '+' || *str == '-') {
			neg = (*str == '-');
			str++;
		}
		unsigned int result = 0;
		unsigned int ABS_INT_MIN = ((unsigned int)INT_MAX) + 1; // abs(INT_MIN) = INT_MAX + 1
		while (isdigit(*str)) {
			unsigned int d = (*str) - '0';
			// boundary check: result * 10 + d > max
			if (result >= INT_MAX / 10) { // rough estimation
				if (!neg && result > (INT_MAX - d) / 10) {
					return INT_MAX;
				}
				if (neg && result > (ABS_INT_MIN - d) / 10) {
					return INT_MIN;
				}
			}
			result = result * 10 + d;
			str++;
		}
		if (neg && result == ABS_INT_MIN) { return INT_MIN; }
		return neg ? -1 * (int)result : result;
	}
	void test() {
		vector<string> v = { "0", "1", "12", "-12", "123", "-1392",
			// INT_MAX(2147483647) or INT_MIN(-2147483648)
			"2147483647", "-2147483648", // INT_MAX, INT_MIN
			"2147483646", "-2147483647", // max - 1, valid
			"2147483648", "-2147483649", // max + 1, invalid
			"999999999999", "-999999999999", // big big
			 };
		for (string s : v) {
			int result = atoi(s.c_str());
			cout << s << " : " << result << endl;
		}
	}
};
