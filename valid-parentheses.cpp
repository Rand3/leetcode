class Solution {
public:
	bool isValid(string s) {
		// https://oj.leetcode.com/problems/valid-parentheses/
		//
		// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
		// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

		stack<char> st;
		for (char c : s) {
			switch (c) {
			case '(':
			case '[':
			case '{':
				st.push(c);
				break;
			case ')':
				if (st.empty() || st.top() != '(') {
					return false;
				}
				st.pop();
				break;
			case ']':
				if (st.empty() || st.top() != '[') {
					return false;
				}
				st.pop();
				break;
			case '}':
				if (st.empty() || st.top() != '{') {
					return false;
				}
				st.pop();
				break;
			default:
				return false;
			}
		}
		return st.empty();
	}
};
