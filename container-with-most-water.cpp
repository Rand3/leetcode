class Solution {
public:
	int maxArea(vector<int> &height) {
		// https://oj.leetcode.com/problems/container-with-most-water/
		//
		// Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
		// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
		// Find two lines, which together with x-axis forms a container, such that the container contains the most water. 
		// Note: You may not slant the container. Slant: slope or lean in a particular direction
		
		int size = height.size();
		if (size < 2) { return 0; }
		int left = 0;
		int right = size - 1;
		int result = 0;
		while (left < right) {
			int area = min(height[left], height[right]) * (right - left);
			result = max(result, area);
			if (height[left] < height[right]) {
				left++;
			}
			else {
				right--;
			}
		}
		return result;
	}
};
