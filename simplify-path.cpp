class Solution {
public:
	string simplifyPath(string path) {
		// https://oj.leetcode.com/problems/simplify-path/
		//
		// Given an absolute path for a file (Unix-style), simplify it.
		// For example,
		//   path = "/home/", => "/home"
		//   path = "/a/./b/../../c/", => "/c"
		// Corner cases:
		//  * Did you consider the case where path = "/../"? In this case, you should return "/".
		//  * multiple slashes like "/home//foo/" should return "/home/foo".

		string invalid = "/";
		deque<string> q;
		int size = (int)path.length();
		if (size == 0 || path[0] != '/') { return invalid; }
		int start = 1;
		for (int i = 1; i <= size; i++) {
			if (i == size || path[i] == '/') {
				int len = i - start;
				if (len == 0 || (len == 1 && path[start] == '.')) {
					; // nothing
				}
				else if (len == 2 && path[start] == '.' && path[start + 1] == '.') {
					if (!q.empty()) {
						q.pop_back();
					}
				}
				else {
					string part = path.substr(start, len);
					q.push_back(part);
				}
				start = i + 1;
			}
		}
		string result;
		for (string part : q) {
			result += '/' + part;
		}
		if (result.length() == 0) {
			result = "/";
		}
		return result;
	}
	void test() {
		vector<string> tests = {
			"/home", "/home/foo", "/home/", "/home//foo/",
			"/a/./b/../../c/",
			"/", "///", "/../"
		};
		for (string s : tests) {
			cout << s << " ==> " << simplifyPath(s) << endl;
		}
	}
};
