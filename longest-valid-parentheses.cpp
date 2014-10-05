class Solution {
public:
	int longestValidParentheses(string s) {
		// https://oj.leetcode.com/problems/longest-valid-parentheses/
		//
		// Given a string containing just the characters '(' and ')', find the length of 
		// the longest valid (well-formed) parentheses substring. 
		// Example 1: "(()", the longest valid parentheses substring is "()", which has length = 2. 
		// Example 2: ")()())", the longest valid parentheses substring is "()()" with length = 4. 

		// Solution: find indexes for unmatched ')' and '(' symbols
		stack<int> st;
		int size = (int)s.length();
		for (int i = 0; i < size; i++) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				if (!st.empty() && s[st.top()] == '(') {
					st.pop();
				}
				else {
					st.push(i);
				}
			}
		}
		int result = 0;
		int last = size;
		while (!st.empty()) {
			int index = st.top();
			st.pop();
			int len = last - index - 1;
			last = index;
			result = max(result, len);
		}
		result = max(result, last); // take care of the very first block
		return result;
	}
	void test() {
		vector<string> tests = {
			"",
			"(",
			")",
			"()",
			")(",
			"(()",
			")()())",
			"()(()()",
			"()()(()",
		};
		for (string s : tests) {
			int len = longestValidParentheses(s);
			cout << s << " : " << len << endl;
		}
	}
};
