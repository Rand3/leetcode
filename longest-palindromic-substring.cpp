class Solution {
public:
	string longestPalindrome(string s) {
		// https://oj.leetcode.com/problems/longest-palindromic-substring/
		//
		// Given a string S, find the longest palindromic substring in S. 
		// You may assume that the maximum length of S is 1000, and there 
		// exists one unique longest palindromic substring.
		// Note: Palindrome means reading the same forward or reversed

		int size = (int)s.length();
		if (size <= 1) { return s; }
		int start = 0;
		int len = 1;
		for (int i = 0; i < size; i++) {
			for (int d = 1; i - d >= 0 && i + d < size && s[i - d] == s[i + d]; d++) {
				if (len < d * 2 + 1) {
					len = d * 2 + 1;
					start = i - d;
				}
			}
		}
		for (int i = 0; i < size - 1; i++) {
			for (int d = 0; i - d >= 0 && i + 1 + d < size && s[i - d] == s[i + 1 + d]; d++) {
				if (len < d * 2 + 2) {
					len = d * 2 + 2;
					start = i - d;
				}
			}
		}
		return s.substr(start, len);
	}
	void test() {
		vector<string> v = { "", "a", "aa", "ab", "aabbaa", "aabaa" };
		for (string s : v) {
			string result = longestPalindrome(s);
			cout << s << " : " << result << endl;
		}
	}
};
