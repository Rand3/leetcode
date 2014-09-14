class Solution  {
public:
	bool isMatch(const char *s, const char *p) {
		// https://oj.leetcode.com/problems/wildcard-matching/
		//
		// implement wildcard pattern matching with support for '?' and '*'.
		//   '?' matches any single character.
		//   '*' matches any sequence of characters (including the empty sequence).
		// the matching should cover the entire input string (not partial).
		//

		// Solution: simply record the last star's position to regress when mismatch happens
		// http://yucoding.blogspot.com/2013/02/leetcode-question-123-wildcard-matching.html
		//
		const char *star = NULL;
		const char *save = s;
		while (*s != '\0') {
			if (*p == *s || *p == '?') {
				s++;
				p++;
			}
			else if (*p == '*') {
				star = p;
				save = s;
				p++;
			}
			else if (star != NULL) { // rewind to last star, eat the saved char
				p = star + 1;
				save++;
				s = save;
			}
			else {
				return false;
			}
		}
		while (*p == '*') {
			p++;
		}
		return (*p == '\0');
	}
	void test() {
		struct TestCase {
			char *s;
			char *pattern;
			bool result;
		};
		vector<TestCase> tests = {
			{ "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb", false },
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
