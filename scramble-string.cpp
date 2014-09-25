class Solution {
public:
    bool isScramble(string s1, string s2) {
        // https://oj.leetcode.com/problems/scramble-string/
        //
        // Given a string s1, we may represent it as a binary tree by 
        // partitioning it to two non-empty substrings recursively. 
        // To scramble the string, we may choose any non-leaf node and 
        // swap its two children.
        //
        // For example, partition string "great" as [gr][e[at]], choose 
        // the node [gr] and swap its two children, we get [rg][e[at]]. 
        // If we continue to swap children of nodes [e[at]] and [at],
        // it produces a scrambled string [rg][[ta]e]. We say that both 
        // both "rgeat" and "rgtae" are scrambled of "great".
        //
        // Given two strings s1 and s2 of the same length, determine if 
        // s2 is a scrambled string of s1.
        int len = s1.length();
        if (len != s2.length()) { return false; }
        if (len == 0) { return true; }
        const char *p1 = s1.c_str();
        const char *p2 = s2.c_str();
        return isScramble(p1, len, p2);
    }
    bool isScramble(const char *p1, int len, const char *p2) {
        if (len == 1) { return (*p1) == (*p2); }
        if (!isShuffle(p1, len, p2)) { return false; }
        for (int i = 1; i < len; i++) {
            int len1 = i; // [0..i)
            int len2 = len - i; // [i..len)
            if (isScramble(p1, len1, p2) && isScramble(p1+len1, len2, p2+len1)) {
                return true;
            }
            if (isScramble(p1, len1, p2+len2) && isScramble(p1+len1, len2, p2)) {
                return true;
            }
        }
        return false;        
    }
    bool isShuffle(const char *p1, int len, const char *p2) {
        unordered_map<char, int> table;
        for (int i = 0; i < len; i++) {
            table[p1[i]] ++;
        }
        for (int i = 0; i < len; i++) {
            char c = p2[i];
            if (table.count(c) == 0 || table[c] == 0) { return false; }
            table[c]--;
        }
        return true;
    }
};
