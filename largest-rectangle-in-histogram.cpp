class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		// https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
		//
		// Given n non-negative integers representing the histogram's bar height 
		// where the width of each bar is 1, find the area of largest rectangle 
		// in the histogram. 
		// For example, Given height = [2,1,5,6,2,3], return 10

		struct Node {
			int height;
			int left;
		};
		stack<Node> s;
		int size = height.size();
		int result = 0;
		for (int i = 0; i <= size; i++) {
			int h = (i == size ? 0 : height[i]);
			int left = i;
			while (!s.empty() && s.top().height > h) {
				left = s.top().left;
				int area = s.top().height * (i - left);
				result = max(result, area);
				s.pop();
			}
			if (s.empty() || s.top().height < h) { // skip if top().height == h
				Node node = { h, left };
				s.push(node);
			}
		}
		return result;
	}
	void test() {
		vector<int> height = { 2, 1, 5, 6, 2, 3 };
		int area = largestRectangleArea(height);
	}
};
