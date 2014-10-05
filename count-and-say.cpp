class Solution {
public:
	string countAndSay(int n) {
		// https://oj.leetcode.com/problems/count-and-say/
		//
		// The count-and-say sequence is the sequence of integers beginning as follows:
		// 1, 11, 21, 1211, 111221, ... 
		// 1 is read off as "one 1" or 11.
		// 11 is read off as "two 1s" or 21.
		// 21 is read off as "one 2, then one 1" or 1211.
		// Given an integer n, generate the nth sequence. 
		// Note: The sequence of integers will be represented as a string.

		string s = "1";
		for (int i = 2; i <= n; i++) {
			string r;
			char prev = s[0];
			int repeat = 1;
			for (int j = 1; j <= (int)s.length(); j++) {
				char c = (j == (int)s.length() ? '\0' : s[j]);
				if (c == prev) {
					repeat++;
				}
				else {
					r += to_string(repeat);
					r += prev;
					prev = c;
					repeat = 1;
				}
			}
			s = r;
		}
		return s;
	}
	void test() {
		int k = 5;
		cout << countAndSay(k) << endl;
	}
};
