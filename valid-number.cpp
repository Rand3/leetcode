class Solution {
public:
	bool isNumber(const char *s) {
		// https://oj.leetcode.com/problems/valid-number/
		//
		// valid number := space* [+-]? (number*) (\.number*) ([E|e][+|-]?number+) space*
		// corner cases: "1.", ".1" are valid, "." are invalid
		//
		while (*s == ' ') {
			s++;
		}
		if (*s == '+' || *s == '-') {
			s++;
		}
		bool integralPart = false;
		if (isdigit(*s)) {
			integralPart = true;
			do {
				s++;
			} while (isdigit(*s));
		}
		else if (*s != '.') { // invalid if not start with [0-9\.]
			return false;
		}
		if (*s == '.') {
			s++;
			if (!integralPart && !isdigit(*s)) { // invalid for "."
				return false;
			}
			while (isdigit(*s)) {
				s++;
			}
		}
		if (*s == 'E' || *s == 'e') {
			s++;
			if (*s == '+' || *s == '-') {
				s++;
			}
			if (!isdigit(*s)) { // invalid if E is not followed by 0-9
				return false;
			}
			do {
				s++;
			} while (isdigit(*s));
		}
		while (*s == ' ') {
			s++;
		}
		return (*s == '\0');
	}
	void test() {
		vector<char*> v = { "", ".", "1.", ".1", "2.e", "2e1", ".e5" };
		for (auto s : v) {
			cout << '[' << s << ']' << isNumber(s) << endl;
		}
	}
};
