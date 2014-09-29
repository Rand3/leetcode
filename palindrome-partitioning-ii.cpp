class Solution {
public:
    int minCut(string s) {
        // https://oj.leetcode.com/problems/palindrome-partitioning-ii/
        //
        // Given a string s, partition s such that every substring of the partition is a palindrome.
        // Return the minimum cuts needed for a palindrome partitioning of s.
        // For example, given s = "aab",
        // Return 1 since the palindrome partitioning["aa", "b"] could be produced using 1 cut.

        // Solution: DP, only requires O(N) space
        // f(k) := minCut(s[1..k]), 0 <= k <= s.len
        // f(k) = min( minCut(i) + 1 ),  if s[i+1,k] is palindrome, and i < k
        int size = (int)s.length();
        vector<int> f(size + 1);
        for (int i = 0; i <= size; i++){
            f[i] = i - 1;
        }
        for (int i = 0; i < size; i++) {
            // find palindrome that is centered at [i]
            for (int d = 0; i - d >= 0 && i + d < size && s[i - d] == s[i + d]; d++) {
                // s[0..i-d-1], s[i-d..i+d]
                f[i + d + 1] = min(f[i + d + 1], f[i - d] + 1);
            }
            // find palindrome that is centered at [i,i+1]
            for (int d = 0; i - d >= 0 && i + 1 + d < size && s[i - d] == s[i + 1 + d]; d++) {
                // s[0..i-d-1], s[i-d..i+1+d]
                f[i + d + 2] = min(f[i + d +2], f[i - d] + 1);
            }
        }
        return f[size];
    }
    void test() {
        string s = "fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi";
        int cut = minCut(s);
        cout << s << ": min cut = " << cut << endl;
    }
};
