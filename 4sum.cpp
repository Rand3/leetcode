class Solution {
public:
	vector<vector<int>> fourSum(vector<int> &num, int target) {
		// https://oj.leetcode.com/problems/4sum/
		//
		// Given an array of n integers, are there elements a, b, c, and d such that a + b + c + d = target? 
		// Find all unique quadruplets in the array which gives the sum of target.
		// Note:
		//  * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d
		//  * The solution set must not contain duplicate quadruplets.
		// For example, given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:
		//    (-1,  0, 0, 1),  (-2, -1, 1, 2),  (-2,  0, 0, 2)

		vector<vector<int>> result;
		int size = (int)num.size();
		if (size < 4) { return result; }
		sort(num.begin(), num.end());
		int first = num[0] - 1; // first will always be different from num[0]
		for (int i = 0; i < size - 3; i++) {
			if (num[i] == first) { continue; }
			first = num[i];
			int second = num[i + 1] - 1;
			for (int j = i + 1; j < size - 2; j++) {
				if (num[j] == second) { continue; }
				second = num[j];
				int t2 = target - (num[i] + num[j]);
				int third = num[j + 1] - 1;
				int left = j + 1;
				int right = size - 1;
				while (left < right) {
					if (num[left] + num[right] == t2) {
						if (num[left] != third) {
							third = num[left];
							vector<int> path = { first, second, third, num[right] };
							result.push_back(path);
						}
						left++;
						right--;
					}
					else if (num[left] + num[right] < t2) {
						left++;
					}
					else {
						right--;
					}
				}
			}
		}
		return result;
	}
	void test() {
		vector<int> num = { -1, 0, -5, -2, -2, -4, 0, 1, -2 }; // { 1, 0, -1, 0, -2, 2 };
		auto result = fourSum(num, -9); // 0
		for (auto v : result) {
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
