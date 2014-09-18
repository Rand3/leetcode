class Solution {
public:
	string intToRoman(int num) {
		// https://oj.leetcode.com/problems/integer-to-roman/
		//
		// Given an integer, convert it to a roman numeral. 
		// Input is guaranteed to be within the range from 1 to 3999.
		//
		// I 1, V 5, X 10, L 50 
		// C 100, D 500, M 1,000
		//
		string s;
		s += help(num / 1000, 'M', ' ', ' ');
		num %= 1000;
		s += help(num / 100, 'C', 'D', 'M');
		num %= 100;
		s += help(num / 10, 'X', 'L', 'C');
		num %= 10;
		s += help(num, 'I', 'V', 'X');
		return s;
	}
	string help(int n, char one, char five, char ten) {
		string s;
		switch (n) {
		case 0: break;
		case 1: s = s + one; break;
		case 2: s = s + one + one; break;
		case 3: s = s + one + one + one; break;
		case 4: s = s + one + five; break;
		case 5: s = s + five; break;
		case 6: s = s + five + one; break;
		case 7: s = s + five + one + one; break;
		case 8: s = s + five + one + one + one; break;
		case 9: s = s + one + ten; break;
		}
		return s;
	}
	void test() {
		string s = intToRoman(8);
		cout << s << endl;
		s = intToRoman(3999);
		cout << s << endl;
	}
};
