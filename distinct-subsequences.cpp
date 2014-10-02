class Solution {
public:
	int numDistinct(string S, string T) {
		// https://oj.leetcode.com/problems/distinct-subsequences/
		//
		// Given a string S and a string T, count the number of distinct subsequences of T in S.
		// A subsequence of a string is a new string which is formed from the original string by 
		// deleting some (can be none) of the characters without disturbing the relative positions 
		// of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
		// For example, given S = "rabbbit", T = "rabbit", Return 3.

		// Clarification: find subsequences in S, such that the subsequence is same as T.
		// In example above, we have
		//   ra*bbit=T
		//   rab*bit=T
		//   rabb*it=T
		// so there're totally 3.

		// Solution: DP
		// f(i,j) := numDisinct(S[first i char], T[first j char])
		// f(i,j) =
		//    S: xxxx | i
		//    T:  yyy | j
		//        + f(i-1,j-1) // if S[i] == T[j], and f(i-1,j-1) is valid
		//    S: xxxx | i
		//    T:  yyyj|
		//        + f(i-1,j) // if f(i-1,j) is valid
		//
		// Sample: S = aa, T = a
		// f(1,1) = 1
		// f(2,1) = f(1,0) // valid, f(any, 0) = 1
		//    	  + f(1, 1) // valid = 1
		//
		// S = aaa
		// T = aa
		//  T: 0 1 2
		// S0  1 0 0
		// S1  1 1 0
		// S2  1 2 1
		// S3  1 3 3
		int rows = S.length();
		int cols = T.length();
		vector<int> f(cols + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= rows; i++) {
			for (int j = cols; j >= 1; j--) {
				if (S[i - 1] == T[j - 1]) {
					f[j] += f[j - 1];
				}
			}
		}
		return f[cols];
	}
};
