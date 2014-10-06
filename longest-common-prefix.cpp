class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		// https://oj.leetcode.com/problems/longest-common-prefix/
		//
		// Find the longest common prefix string amongst an array of strings.

		int len = 0;
		if (strs.size() == 0) { return ""; }
		while (true) {
			char c = '\0';
			for (string &s : strs) {
				if (len == (int)s.size()) {
					return strs[0].substr(0, len);
				}
				if (c == '\0') {
					c = s[len];
				}
				else if (c != s[len]){
					return strs[0].substr(0, len);
				}
			}
			len++;
		}
	}
	void test() {
		vector<string> strs = { "a", "b" };
		string result = longestCommonPrefix(strs);
		cout << result;
	}
};
