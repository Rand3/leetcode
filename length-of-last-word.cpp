class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // https://oj.leetcode.com/problems/length-of-last-word/
        //
        // A word is defined as a character sequence consists of non-space characters only.
        // Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
        // return the length of last word. If the last word does not exist, return 0.
        // For example, Given s = "Hello World", return 5.
        int len = 0;
        if (s == NULL) { return len; }
        while (true) {
            while (*s == ' ') { s++; }
            if (*s == '\0') { break; }
            len = 0;
            while (*s != ' ' && *s != '\0') {
                s++;
                len++;
            }
        }
        return len;
    }
};
