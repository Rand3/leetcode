class Solution {
public:
	string minWindow(string S, string T) {
		// https://oj.leetcode.com/problems/minimum-window-substring/
		//
		// Given a string S and a string T, find the minimum window in S 
		// which will contain all the characters in T in complexity O(n).
		// For example, S = "ADOBECODEBANC", T = "ABC", return "BANC".
		// Note: If there is no such window in S that covers all characters
		// in T, return the emtpy string "". If there are multiple such windows, 
		// assume that there will always be only one unique minimum window in S. 

		// http://leetcode.com/2010/11/finding-minimum-window-in-s-which.html
		//
		unordered_map<char, int> need, found;
		for (char c : T) {
			need[c]++;
		}
		int begin = 0;
		int end = -1;
		int count = 0;
		int best_begin = -1;
		int best_len = INT_MAX;
		for (int i = 0; i < (int)S.length(); i++) {
			char c = S[i];
			if (need.count(c) == 0) {
				continue;
			}
			// find a valid window and record its begin/end
			found[c]++;
			if (found[c] <= need[c]) {
				count++;
			}
			if (count == (int)T.length()) {
				end = i + 1;
				// advance the begin index as far as possible
				while (true) {
					c = S[begin];
					if (need.count(c) == 0) {
						begin++;
					}
					else if (found[c] > need[c]) {
						found[c]--;
						begin++;
					}
					else {
						break;
					}
				}
				if (end - begin < best_len) {
					best_len = end - begin;
					best_begin = begin;
				}
			}
		}
		if (best_len == INT_MAX) {
			return "";
		}
		return S.substr(best_begin, best_len);
	}
};
