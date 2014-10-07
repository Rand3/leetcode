class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int MaxLineLength) {
		// https://oj.leetcode.com/problems/text-justification/
		//
		// Given an array of words and a length L, format the text such that each line has exactly L characters 
		// and is fully (left and right) justified. You should pack as many words as you can in each line. Pad 
		// extra spaces ' ' when necessary so that each line has exactly L characters. Extra spaces between words 
		// should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly 
		// between words, the empty slots on the left will be assigned more spaces than the slots on the right.
		// For the last line of text, it should be left justified and no extra space is inserted between words.
		//
		// For example, Given words: ["This", "is", "an", "example", "of", "text", "justification."], and L: 16.
		// Return the formatted lines as:
		//    "This    is    an",
		//    "example  of text",
		//    "justification.  "

		// * What is the definitin of a "word"? Answr: any group of characters separated by space
		// * What about if a single word is longer than L? A: put it into a new line and left justify it
		// * A line other than the last line might contain only one word. What should I do? A: left justify it
		vector<string> result;
		vector<char> line(MaxLineLength);
		int line_len = 0;  // point to blank space after each word
		int word_count = 0;
		for (string word : words) {
			int len = (int)word.length();
			if (len == 0) { continue; }
			if (line_len + len > MaxLineLength) {
				if (line_len == 0) { // a single very-long word occupies the whole line
					result.push_back(word);
					continue;
				}
				// say, extra space = 11, word_count = 4, the line should format as: w1 4 w2 5 w3 5 w4
				// slot = word_count - 1 = 3.
				// average_space = 11 / 3 = 3 (and then plus original one = 4)
				// plus_count = 11 % 3 = 2 which means the first 2 slot need 5 spaces
				int slot = word_count - 1;
				if (slot == 0) {
					fill(line.begin() + line_len, line.end(), ' ');
				}
				else {
					int extra = MaxLineLength - line_len + 1;
					int average_space = extra / slot + 1;
					int plus_count = extra % slot;
					auto read_pos = line.rbegin() + extra;
					auto write_pos = line.rbegin();
					for (; slot > 0; slot--) {
						while (*read_pos != ' ') {
							*write_pos++ = *read_pos++;
						}
						int space_count = average_space + (slot <= plus_count ? 1 : 0);
						for (; space_count > 0; space_count--) {
							*write_pos++ = ' ';
						}
						read_pos++;
					}
				}
				result.push_back(string(line.begin(), line.end()));
				line_len = 0;
				word_count = 0;
				if (len >= MaxLineLength) {
					result.push_back(word);
					continue;
				}
			}
			auto end = copy(word.begin(), word.end(), line.begin() + line_len);
			if (end != line.end()) {
				*end = ' ';
				line_len += len + 1;
				word_count++;
			}
			else {
				result.push_back(string(line.begin(), line.end()));
				line_len = 0;
				word_count = 0;
			}
		}
		if (line_len != 0 || result.size() == 0) {
			fill(line.begin() + line_len, line.end(), ' ');
			result.push_back(string(line.begin(), line.end()));
		}
		return result;
	}
	void test() {
		vector<pair<vector<string>, int>> tests = {
				{ { "this", "is", "really", "good", "ok===================================================================" }, 30 },
				// 4 + 2 + 6 + 4 = 16, + 3 space = 19, + extra 11 = 30
				{ { "This", "is", "an", "example", "of", "text", "justification." }, 16 },
				{ { "Listen", "to", "many,", "speak", "to", "a", "few." }, 6 },
				{ { "" }, 2 },
		};
		for (auto test : tests) {
			vector<string> words = test.first;
			int len = test.second;
			vector<string> result = fullJustify(words, len);
			for (string s : result) {
				cout << '[' << s << ']' << endl;
			}
			cout << endl;
		}
	}
};
