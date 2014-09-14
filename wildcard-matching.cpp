// DOES NOT WORK, Fail the longer test case
class Solution  {
public:
	static const char nil = '\0';
	bool isMatch(const char *s, const char *p) {
		// https://oj.leetcode.com/problems/wildcard-matching/
		//
		// Implement wildcard pattern matching with support for '?' and '*'.
		//   '?' Matches any single character.
		//   '*' Matches any sequence of characters (including the empty sequence).
		// The matching should cover the entire input string (not partial).
		//
		if (*p == nil) { return *s == nil; }
		// now *p is verified not nil, but *s is still not checked yet.
		// we cannot check *s here for test case like isMatch("", "**");

		if (*p == '*') {
			if (isMatch(s, p + 1)) { // star matches zero char
				return true;
			}
			if (*s == nil) { // before doing s+1, check *s first
				return false;
			}
			return isMatch(s + 1, p); // star matches one or more chars
		}
		else {
			return charMatch(*s, *p) 
				&& isMatch(s + 1, p + 1);
		}
	}
	bool charMatch(char c, char p) {
		return (p == c) || (p == '?' && c != nil);
	}
	void test() {
		struct TestCase {
			char *s;
			char *pattern;
			bool result;
		};
		vector<TestCase> tests = {
			{ "aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b", false },
			{ "ab", "a*a*", false },
			{ "c", "*?*", true },
			{ "c", "?*?", false },
			{ "aa", "a", false },
			{ "aa", "aa", true },
			{ "aaa", "aa", false },
			{ "aa", "*", true },
			{ "aa", "a*", true },
			{ "aa", "?*", true },
			{ "aab", "c*a*b*", false },
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
