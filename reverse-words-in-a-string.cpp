class Solution {
public:
	void reverseWords(string &s) {
		// https://oj.leetcode.com/problems/reverse-words-in-a-string/
		//
		// Given an input string, reverse the string word by word.
		// For example,
		//   Given s = "the sky is blue",
		//   return "blue is sky the".
		//
		// Clarification:
		//  - What constitutes a word?
		//    A sequence of non-space characters constitutes a word.
		//  - Could the input string contain leading or trailing spaces?
		//    Yes. However, your reversed string should not contain leading or trailing spaces.
		//  - How about multiple spaces between two words?
		//    Reduce them to a single space in the reversed string.
		//
		vector<char> result;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == ' ') { continue; }
			// now i points to last char in the word
			int j;
			for (j = i - 1; j >= 0 && s[j] != ' '; j--) {
			}
			// now j points to space before the word, or -1 which is fine
			if (result.size() != 0) {
				result.push_back(' ');
			}
			for (int k = j + 1; k <= i; k++) {
				result.push_back(s[k]);
			}
			i = j; // later i-- wll points to the last char in the word
		}
		s.assign(result.begin(), result.end());
	}
	void test() {
		string s  = " the   sky is  blue ";
		cout << '[' << s << ']' << endl;
		reverseWords(s);
		cout << '[' << s << ']' << endl;
	}
};
