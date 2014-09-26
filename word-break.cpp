class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
        // https://oj.leetcode.com/problems/word-break/
        //
        // Given a string s and a dictionary of words dict, determine if s can be 
        // segmented into a space-separated sequence of one or more dictionary words.
        //
        // For example, given s = "leetcode", dict = ["leet", "code"].
        // Return true because "leetcode" can be segmented as "leet code". 
        
        // Solution (DP)
        // f(k) := wordBreak(s.substr(first k char)), where k <= s.length()
        // f(k) = for any i < k, if (f(i) == true && (word[i,k] in dict))
        int size = (int)s.length();
        vector<bool> f(size+1, false);
        f[0] = true;
        for (int k = 1; k <= size; k++) {
            for (int i = 0; i < k; i++) {
                if (f[i] && dict.count(s.substr(i, k-i)) != 0) {
                    f[k] = true;
                    break;
                }
            }
        }
        return f[size];
	}
};
