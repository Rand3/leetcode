class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		// https://oj.leetcode.com/problems/3sum-closest/
		//
		// Given an array S of n integers, find three integers in S such that 
		// the sum is closest to a given number, target. Return the sum of the 
		// three integers. Assume that each input would have exactly one solution.
		// For example, given array S = {-1, 2, 1, -4}, and target = 1.
		// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

		sort(num.begin(), num.end());
		int result = (target >= 0 ? INT_MAX : INT_MIN);
		int size = (int)num.size();
		for (int i = 0; i < size; i++) {
			int x = num[i];
			int left = i + 1;
			int right = size - 1;
			while (left < right) {
				int total = x + num[left] + num[right];
				if (total == target) { return target; }
				if (total < target) {
					left++;
				}
				else {
					right--;
				}
				if (abs(total - target) < abs(result - target)) {
					result = total;
				}
			}
		}
		return result;
	}
	void test() {
		vector<int> num = { -1, 2, 1, -4 };
		int result = threeSumClosest(num, 1);
		cout << result << endl;
	}
};
