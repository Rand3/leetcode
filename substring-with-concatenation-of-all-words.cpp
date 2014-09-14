class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		// https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
		//
		// You are given a string, S, and a list of words, L, that are all of the same length. 
		// Find all starting indices of substring(s) in S that is a concatenation of each word 
		// in L exactly once and without any intervening characters. 
		// For example, given: 
		//     S: "barfoothefoobarman"
		//     L: ["foo", "bar"]
		// You should return the indices: [0,9]. Order does not matter.
		//
		vector<int> result;
		int count = L.size();
		int len = L[0].length();
		unordered_map<string, int> dict;
		for (int i = 0; i < count; i++) {
			dict[L[i]]++;
		}
		for (int i = 0; i + count * len <= (int)S.length(); i++) {
			unordered_map<string, int> d2;
			int j = 0;
			for (; j < count; j++) {
				string word = S.substr(i + j * len, len);
				if (dict.count(word) == 0) {
					break;
				}
				d2[word]++;
				if (d2[word] > dict[word]) {
					break;
				}
			}
			if (j == count) {
				result.push_back(i);
			}
		}
		return result;
	}
	void test() {
		string bigS(700, 'a');
		vector<string> bigL(600, "a");
		struct TestCase {
			string S;
			vector<string> L;
		} tests[] = {
			{ "a", { "a" } },
			{ "barfoothefoobarman", { "foo", "bar" } },
			{ bigS, bigL }
		};
		for (auto test : tests) {
			vector<int> result = findSubstring(test.S, test.L);
			for (int i : result) {
				cout << i << ' ';
			}
			cout << endl;
		}
	}
};
