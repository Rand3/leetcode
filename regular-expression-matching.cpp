class Solution {
public:
	static const char nil = '\0';
	bool isMatch(const char *s, const char *p) {
		// https://oj.leetcode.com/problems/regular-expression-matching/
		//
		// Implement regular expression matching with support for '.' and '*'.
		//   '.' Matches any single character
		//   '*' Matches zero or more of the preceding element
		// The matching should cover the entire input string (not partial).
		//

		if (*p == nil) { return *s == nil; }
		// now *p is verified not nil, but *s is still not checked yet

		// trick: instead of looking at the current char, look ahead to check
		// whether we need to handle the difficult part (star)
		if (*(p+1) == '*') {
			if (isMatch(s, p + 2)) { // star matches zero count of instance
				return true;
			}
			return charMatch(*s, *p) // star matches one or more counts
				&& isMatch(s + 1, p);
		}
		else {
			return charMatch(*s, *p) 
				&& isMatch(s + 1, p + 1);
		}
	}
	bool charMatch(char c, char p) {
		return (p == c) || (p == '.' && c != nil);
	}
	void test() {
		struct TestCase {
			char *s;
			char *pattern;
			bool result;
		};
		vector<TestCase> tests = {
			{ "ab", ".*c", false },
			{ "aa", "a", false },
			{ "aa", "aa", true },
			{ "aaa", "aa", false },
			{ "aa", "a*", true },
			{ "aa", ".*", true },
			{ "ab", ".*", true },
			{ "aab", "c*a*b*", true },
			{ "aaaab", "a*a*a*a*a*", false }
		};
		for (auto test : tests) {
			bool result = isMatch(test.s, test.pattern);
			if (result != test.result) {
				cout << "ERROR: isMatch(" << test.s << ", " << test.pattern << ") returned " << result << endl;
			}
		}
	}
};
