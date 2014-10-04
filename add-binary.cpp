class Solution {
public:
	string addBinary(string a, string b) {
		// https://oj.leetcode.com/problems/add-binary/
		//
		// Given two binary strings, return their sum (also a binary string).
		// For example, a = "11", b = "1", Return "100".

		int m = (int)a.length();
		int n = (int)b.length();
		int size = max(m, n);
		string result(size, '0');
		int carry = 0;
		for (int i = 0; i < size; i++) {
			int c1 = (i >= m) ? 0 : a[m - 1 - i] - '0';
			int c2 = (i >= n) ? 0 : b[n - 1 - i] - '0';
			int c = c1 + c2 + carry;
			if (c >= 2) {
				c -= 2;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result[size - 1 - i] = '0' + c;
		}
		if (carry) {
			string one = "1";
			result = one + result;
		}
		return result;
	}
};
