class Solution {
public:
    bool isPalindrome(string s) {
        // https://oj.leetcode.com/problems/valid-palindrome/
        //
        // Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases
        // For example,
        //   "A man, a plan, a canal: Panama" is a palindrome.
        //   "race a car" is not a palindrome. 
        //
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
            }
            else if (!isalnum(s[j])) {
                j--;
            }
            else {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
