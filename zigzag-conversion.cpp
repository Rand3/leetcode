class Solution {
public:
	string convert(string s, int nRows) {
		// https://oj.leetcode.com/problems/zigzag-conversion/
		//
		// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
		// like this, and then read line by line: "PAHNAPLSIIGYIR"
		//   P   A   H   N
		//   A P L S I I G
		//   Y   I   R
		// Write the code that will take a string and make this conversion given a number of rows: 
		// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 

		if (nRows == 1) { return s; }
		vector<vector<char>> rows(nRows);
		int i = 0;
		bool down = true;
		for (char c : s) {
			rows[i].push_back(c);
			if (down) {
				i++;
				if (i == nRows - 1) {
					down = false;
				}
			}
			else {
				i--;
				if (i == 0) {
					down = true;
				}
			}
		}
		string result;
		for (vector<char> v : rows) {
			result.append(v.begin(), v.end());
		}
		return result;
	}
	void test() {
		string s = "PAYPALISHIRING";
		string result = convert(s, 3);
		cout << result << endl;
	}
};
