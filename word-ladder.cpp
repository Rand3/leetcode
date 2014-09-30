class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// https://oj.leetcode.com/problems/word-ladder/
		//
		// Given two words (start and end), and a dictionary, find the length 
		// of shortest transformation sequence from start to end, such that:
		//   1. Only one letter can be changed at a time
		//   2. Each intermediate word must exist in the dictionary
		//
		// For example, Given: start = "hit", end = "cog", dict = ["hot","dot","dog","lot","log"]
		// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
		// return its length 5.
		//
		// Note:
		//   * Return 0 if there is no such transformation sequence.
		//   * All words have the same length.
		//   * All words contain only lowercase alphabetic characters.

		if (start == end) { return 1; }
		queue<string> q;
		q.push(start);
		int width = (int)start.length();
		int len = 2;
		while (!q.empty()) {
			int size = (int)q.size();
			for (int i = 0; i < size; i++) {
				string s = q.front();
				q.pop();
				for (int j = 0; j < width; j++) {
					char save = s[j];
					for (int c = 'a'; c <= 'z'; c++) {
						if (c == save) { continue; }
						s[j] = c;
						if (s == end) { return len; }
						if (dict.count(s) != 0) {
							q.push(s);
							dict.erase(s);
						}
					}
					s[j] = save;
				}
			}
			len++;
		}
		return 0;
	}
	void test() {
		string start = "hit";
		string end = "cog";
		unordered_set<string> dict = { "hot", "dot", "dog", "lot", "log" };
		int len = ladderLength(start, end, dict);
		cout << len << endl;
	}
};
