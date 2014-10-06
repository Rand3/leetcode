class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &num) {
		// https://oj.leetcode.com/problems/3sum/
		//
		// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
		// Find all unique triplets in the array which gives the sum of zero.
		// Note:
		//  * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
		//  * The solution set must not contain duplicate triplets.
		// For example, given array S = {-1, 0, 1, 2, -1, -4},
		// A solution set is:  (-1, 0, 1)  (-1, -1, 2)

		vector<vector<int>> result;
		int size = (int)num.size();
		if (size == 0) { return result; }
		sort(num.begin(), num.end());
		int prev = num[0] - 1;
		for (int i = 0; i < (int)num.size(); i++) {
			int target = num[i];
			if (target == prev) { continue; }
			prev = target;
			int left = i + 1;
			int right = size - 1;
			int prev2 = num[0] - 1;
			while (left < right) {
				int total = target + num[left] + num[right];
				if (total == 0) {
					if (num[left] != prev2) {
						prev2 = num[left];
						vector<int> path = { target, num[left], num[right] };
						result.push_back(path);
					}
					left++;
					right--;
				}
				else if (total < 0) {
					left++;
				}
				else {
					right--;
				}
			}
		}
		return result;
	}
	void test() {
		vector<int> num = { -1, 0, 1, 2, -1, -4 };
		vector<vector<int>> result = threeSum(num);
		for (auto v : result) {
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
