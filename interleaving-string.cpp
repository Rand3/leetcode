class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// https://oj.leetcode.com/problems/interleaving-string/
		//
		// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
		// For example, Given: s1 = "aabcc", s2 = "dbbca",
		// When s3 = "aadbbcbcac", return true.
		// When s3 = "aadbbbaccc", return false.

		// Solution: DP
		// f(i,j) := isInterleave(s1[first i char], s2[first j], s3[first i+j])
		// f(i,j) = f(i,j-1) && (s3[i+j] == s2[j])
		//       || f(i-1,j) && (s3[i+j] == s1[i])
		// Edges casess f(0,x), f(x,0) need be calculated individually
		//
		// [i-1,j-1] [i-1,j]
		// [i,j-1]   [i,j]
		// f(j) = (f(j-1) && s3[]==s2[j]) || (f(j) && s3[]==s1[i])
		// 
		int rows = (int)s1.length();
		int cols = (int)s2.length();
		if (rows + cols != (int)s3.length()) { return false; }
		vector<bool> f(cols + 1);
		f[0] = true;
		for (int j = 0; j < cols; j++) {
			f[j + 1] = (s3[j] == s2[j] && f[j]);
		}
		for (int i = 1; i <= rows; i++) {
			f[0] = (s3[i - 1] == s1[i - 1] && f[0]);
			for (int j = 1; j <= cols; j++) {
				bool r = false;
				if (s3[i + j - 1] == s2[j - 1] && f[j - 1]) {
					r = true;
				}
				if (s3[i + j - 1] == s1[i - 1] && f[j]) {
					r = true;
				}
				f[j] = r;
			}
		}
		return f[cols];
	}
	void test() {
		struct TestCase {
			string s1, s2, s3;
			bool result;
		};
		TestCase tests[] = {
				{ "a", "", "c", false },
				{ "aabcc", "dbbca", "aadbbcbcac", true },
				{ "aabcc", "dbbca", "aadbbbaccc", false },
		};
		for (TestCase test : tests) {
			bool b = isInterleave(test.s1, test.s2, test.s3);
			cout << "isInterleave(" << test.s1 << ',' << test.s2 << ',' << test.s3 << ") returns " << b;
			if (b != test.result) {
				cout << " *** ERROR *** ";
			}
			cout << endl;
		}
	}
};
