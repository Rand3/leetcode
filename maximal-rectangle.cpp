class Solution {
public:
	int maximalRectangle(vector<vector<char>> &matrix) {
		// https://oj.leetcode.com/problems/maximal-rectangle/
		//
		// Given a 2D binary matrix filled with 0's and 1's, find the
		// largest rectangle containing all ones and return its area. 
		//
		int result = 0;
		int rows = (int)matrix.size();
		if (rows == 0) { return result; }
		int cols = (int)matrix[0].size();
		if (rows == 0) { return result; }
		// construct height[], where each h is defined as the consecutive 
		// number of 1's from current row to top row
		vector<int> height(cols);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (i == 0) {
					height[j] = (matrix[i][j] == '1' ? 1 : 0);
				}
				else {
					if (matrix[i][j] == '1') {
						if (matrix[i - 1][j] == '1') {
							height[j]++;
						}
						else {
							height[j] = 1;
						}
					}
					else {
						height[j] = 0;
					}
				}
			}
			int area = largestRectangleArea(height);
			result = max(result, area);
		}
		return result;
	}
	int largestRectangleArea(vector<int> &height) {
		// https://oj.leetcode.com/problems/largest-rectangle-in-histogram/
		//
		int result = 0;
		int size = (int)height.size();
		struct Node {
			int height;
			int left;
			Node(int h, int l) : height(h), left(l) {}
		};
		stack<Node> s;
		for (int i = 0; i <= size; i++) {
			int left = i;
			int h = (i == size ? 0 : height[i]);
			while (!s.empty() && h < s.top().height) {
				left = s.top().left;
				int area = (i - left) * s.top().height;
				result = max(result, area);
				s.pop();
			}
			// the only time when we do not push: h == s.top().height
			while (s.empty() || h > s.top().height) {
				s.push(Node(h, left));
			}
		}
		return result;
	}
	void test() {
		vector<string> m = {
			"1011",
			"1111",
			"1110"
		};
		vector<vector<char>> matrix;
		for (string &s : m) {
			matrix.push_back(vector<char>(s.begin(), s.end()));
		}
		int result = maximalRectangle(matrix);
		cout << result << endl;
	}
};
