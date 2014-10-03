class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		// https://oj.leetcode.com/problems/restore-ip-addresses/
		//
		// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
		// For example:  Given "25525511135",  return ["255.255.11.135", "255.255.111.35"]. (Order does not matter) 

		vector<string> result;
		int dots[4];
		dots[0] = 0;
		help(s, 1, dots, result);
		return result;
	}
	void help(string &s, int level, int dots[], vector<string> &result) {
		// level: 1, 2, 3, 4
		if (level <= 3) {
			for (int len = 1; len <= 3; len++) {
				if (isValid(s, dots[level - 1], len)) {
					dots[level] = dots[level - 1] + len;
					help(s, level + 1, dots, result);
				}
			}
		}
		else {
			int len = s.length() - dots[3];
			if (len >= 1 && len <= 3 && isValid(s, dots[3], len)) {
				string ip = s.substr(0, dots[1]) + '.'
					+ s.substr(dots[1], dots[2] - dots[1]) + '.'
					+ s.substr(dots[2], dots[3] - dots[2]) + '.'
					+ s.substr(dots[3], len);
				result.push_back(ip);
			}
		}
	}
	bool isValid(string &s, int start, int len) {
		if (start + len > (int)s.length()) {
			return false;
		}
		if (s[start] == '0') {
			return (len == 1);
		}
		int n = s[start] - '0';
		if (len > 1) {
			n = (n * 10) + (s[start + 1] - '0');
		}
		if (len > 2) {
			n = (n * 10) + (s[start + 2] - '0');
		}
		return (n < 256);
	}
	void test() {
		string s = "25525511135";
		vector<string> v = restoreIpAddresses(s);
		for (string ip : v) {
			cout << ip << endl;
		}
	}
};
