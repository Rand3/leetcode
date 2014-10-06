class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		// https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
		//
		// Given a string, find the length of the longest substring without repeating characters. 
		// For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
		// which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

		unordered_set<char> table;
		int size = (int)s.length();
		if (size <= 1) { return size; }
		int start = 0;
		int result = 0;
		for (int i = 0; i < size; i++) {
			char c = s[i];
			if (table.count(c) == 0) {
				table.insert(c);
				result = max(result, i + 1 - start);
			}
			else {
				while (s[start] != c) {
					table.erase(s[start]);
					start++;
				}
				start++;
			}
		}
		return result;
	}
	void test() {
		vector<string> v = { "abcabcbb", "bbbbb", "a", "",
			"hchzvfrkmlnozjk",
			"wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco" };
		for (string s : v) {
			int result = lengthOfLongestSubstring(s);
			cout << s << " : " << result << endl;
		}
	}
};
