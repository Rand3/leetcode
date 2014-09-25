class Solution {
public:
	const static char nil = '\0';
	char *strStr(char *haystack, char *needle) {
		// https://oj.leetcode.com/problems/implement-strstr/
		//
		// Returns a pointer to the first occurrence of needle in haystack, 
		// or null if needle is not part of haystack.
		if (haystack == NULL || needle == NULL) { return NULL; }
		if (*needle == nil) { return haystack; }

		// special optimization for repeat in needle
		char *p = needle + 1;
		while (*p == *needle && *p != nil) { p++; }
		int repeat = (p - needle);
		int skip = 0;
		
		while (*haystack != nil) {
		    char *p = haystack + skip;
		    char *q = needle + skip;
		    while (*p == *q && *q != nil) {
		        p++;
		        q++;
		    }
		    if (*q == nil) {
		        return haystack;
		    }
		    // hay     aaaab. match >=3, skip = 2
		    //         aab    match = 2, skip = 1
		    //         ab     match = 1, skip = 0
		    //         b      match = 0, skip = 0
		    // needle: aaa...
		    //          aaa..
		    int matchCount = p - haystack;
		    skip = min(matchCount, repeat) - 1;
		    if (skip < 0) { skip = 0; }
		    haystack++;
		}
		return NULL;
	}
};
