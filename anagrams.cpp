class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		// https://oj.leetcode.com/problems/anagrams/
		//
		// Given an array of strings, return all groups of strings that are anagrams. 
		// Note: All inputs will be in lower-case.
		// Note: anagram = re-arrange

		vector<string> result;
		unordered_map<string, vector<string>> table; // map normallized string to original strings
		for (string s : strs) {
			string tmp = s;
			sort(tmp.begin(), tmp.end());
			table[tmp].push_back(s);
		}
		for (auto x : table) {
			if (x.second.size() != 1) {
				result.insert(result.end(), x.second.begin(), x.second.end());
			}
		}
		return result;
	}
};
