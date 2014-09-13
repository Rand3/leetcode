class Solution {
public:
	const static int invalid = -1;
	int romanToInt(string s) {
		// https://oj.leetcode.com/problems/roman-to-integer/
		//
		// Given a roman numeral, convert it to an integer.
		// Input is guaranteed to be within the range from 1 to 3999.
		//
		// Symbols: I 1, V 5, X 10, L 50, C 100, D 500, M 1000
		// Rules:   1..3 = I, II, III, 4 = IV, 5 = V
		//          6..8 = VI, VII, VIII, 9 = IX, 10 = X
		//
		// - from left to right, 1000 firt, then 100, then 10, then 1
		// - 1,10,100,1000 can repeat at most 3 times
		// - 1 can be placed before 5 and 10 to make 4 and 9 respectively
		// - 10 can be placed before 50 and 100 to make 40 and 90
		// - 100 can be placed before 500 and 1000 to make 400 and 900
		// 
		// Biggest number = 3x1000 + (1000-100) + (100-10) + (10-1)
		//    = MMM.CM.XC.IX
		//
		int result = 0;
		for (size_t i = 0; i < s.length(); i++) {
			int n = romanToInt(s[i]);
			if ((n == 1 || n == 10 || n == 100) && i + 1 < s.length()) {
				int next = romanToInt(s[i + 1]);
				if (validSubtraction(n, next)) {
					n = next - n;
					i++;
				}
			}
			result += n;
		}
		return result;
	}
	int romanToInt(char c) {
		int i;
		switch (c) {
		case 'I': i = 1; break;
		case 'V': i = 5; break;
		case 'X': i = 10; break;
		case 'L': i = 50; break;
		case 'C': i = 100; break;
		case 'D': i = 500; break;
		case 'M': i = 1000; break;
		default: i = invalid;
		}
		return i;
	}
	bool validSubtraction(int n, int next) {
		return (n == 1 && (next == 5 || next == 10)) ||
			(n == 10 && (next == 50 || next == 100)) ||
			(n == 100 && (next == 500 || next == 1000));
	}
	string intToRoman(int n) {
		string result;
		if (n <= 0 || n >= 4000) { return result; }
		result += helper(n / 1000, 'M', ' ', ' ');
		n %= 1000;
		result += helper(n / 100, 'C', 'D', 'M');
		n %= 100;
		result += helper(n / 10, 'X', 'L', 'C');
		n %= 10;
		result += helper(n, 'I', 'V', 'X');
		return result;
	}
	string helper(int n, char one, char five, char ten) {
		string s;
		switch (n) {
		case 0: break;
		case 1: s = one; break;
		case 2: s = s + one + one; break;
		case 3: s = s + one + one + one; break;
		case 4: s = s + one + five; break;
		case 5: s = five; break;
		case 6: s = s + five + one; break;
		case 7: s = s + five + one + one; break;
		case 8: s = s + five + one + one + one; break;
		case 9: s = s + one + ten; break;
		}
		return s;
	}
	void test() {
		for (int i = 1; i <= 3999; i++) {
			string roman = intToRoman(i);
			int n = romanToInt(roman);
			if (i != n) {
				cout << "ERROR: " << i << " => roman " << roman << " => " << n << endl;
			}
		}
	}
};
