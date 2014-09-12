class Solution {
public:
	// https://oj.leetcode.com/problems/two-sum/
	//
	// Given an array of integers, find two numbers such that they add up to a specific target number.
	// The function twoSum should return indices of the two numbers such that they add up to the target, 
	// where index1 must be less than index2. Please note that your returned answers (both index1 and 
	// index2) are not zero-based. You may assume that each input would have exactly one solution.
	//
	// Input: numbers={2, 7, 11, 15}, target=9
	// Output: index1=1, index2=2
	//
	vector<int> twoSum(vector<int> &numbers, int target) {
		int size = (int)numbers.size();
		vector<int> sorted = numbers;
		sort(sorted.begin(), sorted.end());
		int left = 0;
		int right = size - 1;
		while (left < right) {
			int sum = sorted[left] + sorted[right];
			if (sum < target) {
				left++;
			}
			else if (sum > target) {
				right--;
			}
			else {
				break;
			}
		}
		vector<int>::iterator it1 = find(numbers.begin(), numbers.end(), sorted[left]);
		vector<int>::iterator start = (sorted[left] == sorted[right] ? it1 + 1 : numbers.begin());
		vector<int>::iterator it2 = find(start, numbers.end(), sorted[right]);
		if (it1 > it2) {
			swap(it1, it2);
		}
		vector<int> result = { (int)(it1 - numbers.begin() + 1), (int)(it2 - numbers.begin() + 1) };
		return result;
	}
	void test() {
		//vector<int> numbers = { 2, 7, 11, 15 };
		//int target = 9;
		//vector<int> numbers = { 5, 10, 5, 11, 15 };
		//int target = 10;
		vector<int> numbers = { 7, 2, 11, 15 };
		int target = 9;
		vector<int> result = twoSum(numbers, target);
		cout << result[0] << ", " << result[1] << endl;
	}
};
