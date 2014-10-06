class Solution {
public:
	vector<string> letterCombinations(string digits) {
		// https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
		//
		// Given a digit string, return all possible letter combinations that the number could represent. 
		// A mapping of digit to letters (just like on the telephone buttons) is given below.
		// 1 - <mailbox>
		// 2 - abc
		// 3 - def
		// 4 - ghi
		// 5 - jkl
		// 6 - mno
		// 7 - pqrs
		// 8 - tuv
		// 9 - wxyz
		// *+
		// 0 - <space>
		// #
		// Input: Digit string "23"
		// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
		// Note: Although the above answer is in lexicographical order, your answer could be in any order you want. 

		vector<string> phone = {
			" ", "", "abc", "def", "ghi",
			"jkl", "mno", "pqrs", "tuv", "wxyz"
		};
		help(digits, 0, phone);
		return result;
	}
	vector<string> result;
	string path;
	void help(string &digits, int index, vector<string> &phone) {
		if (index == (int)digits.size()) {
			result.push_back(path);
			return;
		}
		int n = digits[index] - '0';
		for (char c : phone[n]) {
			path.push_back(c);
			help(digits, index + 1, phone);
			path.pop_back();
		}
	}
};
