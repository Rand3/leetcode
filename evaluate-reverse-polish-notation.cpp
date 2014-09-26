class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		// https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
		//
		// Evaluate the value of an arithmetic expression in http://en.wikipedia.org/wiki/Reverse_Polish_notation
		// Valid operators are +, -, *, /. Each operand may be an integer or another expression. 
		// Some examples:
		//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
		//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
		stack<int> s;
		for (string w : tokens) {
			int a, b;
			if (w.length() == 1 && !isdigit(w[0])) {
				b = s.top();
				s.pop();
				a = s.top();
				switch (w[0]) {
				case '+': s.top() = a + b; break;
				case '-': s.top() = a - b; break;
				case '*': s.top() = a * b; break;
				case '/': s.top() = a / b; break;
				}
			}
			else {
				a = atoi(w.c_str());
				s.push(a);
			}
		}
		return s.top();
	}
	void test() {
		vector<string> tokens = { "-1", "1", "*", "-1", "+" };
		int result = evalRPN(tokens);
	}
};
