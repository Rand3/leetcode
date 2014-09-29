class Solution {
public:
    vector<vector<string>> partition(string s) {
        // https://oj.leetcode.com/problems/palindrome-partitioning/
        //
        // Given a string s, partition s such that every substring of the partition is a palindrome.
        // Return all possible palindrome partitioning of s. For example, given s = "aab",
        // Return [ ["aa", "b"], ["a", "a", "b"] ]

        vector<string> path;
        vector<vector<string>> result;
        dfs(s, 0, path, result);
        return result;
    }
    void dfs(string &s, int begin, vector<string> &path, vector<vector<string>> &result) {
        if (begin == s.length()) {
            result.push_back(path);
            return;
        }
        for (int end = begin + 1; end <= s.length(); end++) {
            if (isPalindrome(s, begin, end)) {
                path.push_back(s.substr(begin, end - begin));
                dfs(s, end, path, result);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int begin, int end) {
        // check whether s[begin,end) is valid
        end--;
        while (begin < end) {
            if (s[begin] != s[end]) {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
};
