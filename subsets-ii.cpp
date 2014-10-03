class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int> &S) {
		// https://oj.leetcode.com/problems/subsets-ii/
		//
		// Given a collection of integers that might contain duplicates, S, return all possible subsets.
		// Note:
		//  * Elements in a subset must be in non-descending order.
		//  * The solution set must not contain duplicate subsets.
		// For example, If S = [1,2,2], a solution is:
		// [ [2],  [1],  [1,2,2],  [2,2],  [1,2],  [] ]

		// Solution: DP
		// f(k) := subsets(first k elements in S)
		// f(k) = f(k-1) 
		//      + {f(k-1), S[k]} // if S[k] != S[k-1]
		//      + {f(k-m), m*S[K]} // if there are m duplicate of S[k] at the end of S
		sort(S.begin(), S.end());
		int size = (int)S.size();
		vector<vector<vector<int>>> f(size + 1);
		vector<int> empty_set;
		f[0].push_back(empty_set);
		if (size == 0) { return f[0]; }
		vector<int> one_element;
		one_element.push_back(S[0]);
		f[1] = f[0];
		f[1].push_back(one_element);
		int prev = 0; // 1-based index before dup char; prev+1 is the start of dup char
		for (int k = 2; k <= size; k++) {
			f[k] = f[k - 1];
			if (S[k - 1] != S[prev]) { // S is 0-based. therefore start of dup char (prev+1) is S[(prev+1)-1] = S[prev]
				prev = k - 1;
			}
			int prevSize = (int)f[prev].size();
			vector<int> repeat(k - prev, S[prev]);
			for (int i = 0; i < prevSize; i++) {
				vector<int> row = f[prev][i];
				row.insert(row.end(), repeat.begin(), repeat.end());
				f[k].push_back(row);
			}
		}
		return f[size];
	}
	void test() {
		vector<int> S = { 1, 2, 2, 2 };
		vector<vector<int>> subset = subsetsWithDup(S);
		for (vector<int> v : subset) {
			cout << "[ ";
			for (int x : v) {
				cout << x << ' ';
			}
			cout << "]" << endl;
		}
	}
};
