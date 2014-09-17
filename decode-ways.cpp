class Solution {
public:
	int numDecodings(string s) {
		// https://oj.leetcode.com/problems/decode-ways/
		//
		// A message containing letters from A-Z is being encoded to numbers using the following mapping:
		//    A->1, B->2, ..., Z->26
		// Given an encoded message containing digits, determine the total number of ways to decode it.
		// For example,
		// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
		// The number of ways decoding "12" is 2.

		// Solution: DP
		//  f(k) := num of decoding for s[0..k]
		//  f(k+1) = f(k)   // if last char is not zero
		//         + f(k-1) // lf last two is 10-26
		int len = s.length();
		if (len == 0) { return 0; }
		int f0 = 1; // this is for decode("20") = 1
		int prev = (s[0] - '0');
		int f1 = (prev == 0 ? 0 : 1);
		if (len == 1) { return f1; }
		int result;
		for (int i = 1; i < len; i++) {
			int n1 = s[i] - '0';
			int f = 0;
			if (n1 != 0) {
				f += f1;
			}
			int n2 = prev * 10 + n1;
			if (n2 >= 10 && n2 <= 26) {
				f += f0;
			}
			f0 = f1;
			f1 = f;
			result = f;
			prev = n1;
		}
		return result;
	}
	void test() {
		vector<string> v = {
			"1", "0", "12", "123", "1223", "10"
		};
		for (string s : v) {
			int num = numDecodings(s);
			cout << s << " : " << num << endl;
		}
	}
};
