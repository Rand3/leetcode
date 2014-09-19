class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		// https://oj.leetcode.com/problems/word-break-ii/
		//
		// Given a string s and a dictionary of words dict, add spaces in s 
		// to construct a sentence where each word is a valid dictionary word.
		// Return all such possible sentences.
		//
		// For example, given
		//   s = "catsanddog",
		//   dict = ["cat", "cats", "and", "sand", "dog"].
		// A solution is ["cats and dog", "cat sand dog"].
		//

		// Solution: this is a tree traversal problem.
		int len = s.length();
		vector<vector<int>> words(len);
		// words[0] = { 3, 4 } which means s[0..2] = "cat" and s[0..3] = "cats" are in dict
		for (int end = len; end > 0; end--) {
			// important optimization: remove any dead path (i.e. those cannot reach finish line)
			if (end != len && words[end].size() == 0) {
				continue;
			}
			for (int begin = end - 1; begin >= 0; begin--) {
				string sub = s.substr(begin, end - begin);
				if (dict.count(sub) != 0) {
					words[begin].push_back(end);
				}
			}
		}
		vector<string> result;
		string path;
		travel(words, 0, path, s, result);
		return result;
	}
	void travel(vector<vector<int>> &words, int begin, string &path, string &s, vector<string> &result) {
		int len = s.length();
		if (begin == len) {
			result.push_back(path);
			return;
		}
		vector<int> &steps = words[begin];
		for (int end : steps) {
			string sub = s.substr(begin, end - begin);
			string nextPath = path + (begin == 0 ? sub : " " + sub);
			travel(words, end, nextPath, s, result);
		}
	}
	void test() {
		string s = "catsanddog"; // "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		vector<string> words = { "cat", "cats", "and", "sand", "dog" }; // { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
		unordered_set<string> dict;
		for (string s : words) {
			dict.insert(s);
		}
		vector<string> result = wordBreak(s, dict);
		for (string s : result) {
			cout << s << endl;
		}
	}
};
