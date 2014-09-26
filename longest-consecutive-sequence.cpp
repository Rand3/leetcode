class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // https://oj.leetcode.com/problems/longest-consecutive-sequence/
        //
        // Given an unsorted array of integers, find the length of the longest 
        // consecutive elements sequence.
        // For example, Given [100, 4, 200, 1, 3, 2], return 4 for [1, 2, 3, 4].
        // Your algorithm should run in O(n) complexity.
        
        int result = 0;
        if (num.size() == 0) { return result; }
        unordered_set<int> s;
        for (int n: num) {
            s.insert(n);
        }
        while (s.size() != 0) {
            int n = *(s.begin());
            int len = 1;
            s.erase(n);
            int i = 1;
            // while using 2 loops, this is still O(N) instead of O(N^2),
            // as each n will be visited at most 3 times.
            for (; s.count(n-i) != 0; i++) {
                s.erase(n-i);
            }
            len += i-1;
            i = 1;
            for (; s.count(n+i) != 0; i++) {
                s.erase(n+i);
            }
            len += i-1;
            result = max(result, len);
        }
        return result;
    }
};
