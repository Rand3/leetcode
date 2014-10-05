class Solution {
public:
	string multiply(string num1, string num2) {
		// https://oj.leetcode.com/problems/multiply-strings/
		//
		// Given two numbers represented as strings, return multiplication of the numbers as a string.
		// Note: The numbers can be arbitrarily large and are non-negative.

		int len1 = (int)num1.length();
		int len2 = (int)num2.length();
		if ((len1 == 1 && num1[0] == '0') || (len2 == 1 && num2[0] == '0')) {
			return "0";
		}
		string result(len1 + len2, '0');
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				int x = (num1[i] - '0') * (num2[j] - '0');
				int carry = x / 10;
				int one = x % 10;
				int k = i + j + 1;
				x = (result[k] - '0') + one;
				if (x >= 10) {
					x -= 10;
					carry++;
				}
				result[k] = '0' + x;
				while (carry != 0) {
					k--;
					x = (result[k] - '0') + carry;
					if (x >= 10) {
						x -= 10;
						carry = 1;
					}
					else {
						carry = 0;
					}
					result[k] = '0' + x;
				}
			}
		}
		if (result[0] == '0') {
			result.erase(result.begin());
		}
		return result;
	}
	void test() {
		vector<string> v = {
			"99", "0",
			"0", "0",
			"1", "1",
			"10", "10",
			"99", "99"
		};
		for (int i = 0; i < (int)v.size(); i += 2) {
			string num1 = v[i];
			string num2 = v[i + 1];
			string result = multiply(num1, num2);
			cout << num1 << " x " << num2 << " = " << result << endl;
		}
	}
};
