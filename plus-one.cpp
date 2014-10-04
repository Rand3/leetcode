class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		// https://oj.leetcode.com/problems/plus-one/
		//
		// Given a non-negative number represented as an array of digits, plus one to the number.
		// The digits are stored such that the most significant digit is at the head of the list.

		int size = digits.size();
		vector<int> result(size);
		int carry = 1;
		for (int i = size - 1; i >= 0; i--) {
			int n = digits[i] + carry;
			if (n > 9) {
				n = 0;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result[i] = n;
		}
		if (carry) {
			result.push_back(0);
			for (int i = size - 1; i >= 0; i--) {
				result[i + 1] = result[i];
			}
			result[0] = 1;
		}
		return result;
	}
};
