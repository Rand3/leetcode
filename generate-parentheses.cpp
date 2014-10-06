class Solution {
public:
	vector<string> generateParenthesis(int n) {
		// https://oj.leetcode.com/problems/generate-parentheses/
		//
		// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
		// For example, given n = 3, a solution set is: "((()))", "(()())", "(())()", "()(())", "()()()" 

		help(n, n);
		return result;
	}
	string path;
	vector<string> result;
	void help(int left, int right) {
		if (left == 0 && right == 0) {
			result.push_back(path);
			return;
		}
		if (left > 0) {
			path.push_back('(');
			help(left - 1, right);
			path.pop_back();
		}
		if (right > 0 && left < right) {
			path.push_back(')');
			help(left, right - 1);
			path.pop_back();
		}
	}
	void test() {
		vector<string> result = generateParenthesis(3);
		for (string s : result) {
			cout << s << endl;
		}
	}
};
