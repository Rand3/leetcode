class Solution {
public:
	void nextPermutation(vector<int> &num) {
		// https://oj.leetcode.com/problems/next-permutation/
		//
		// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers. 
		// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order). 
		// The replacement must be in-place, do not allocate extra memory. 
		// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
		// 1,2,3 => 1,3,2
		// 3,2,1 => 1,2,3
		// 1,1,5 => 1,5,1

		// 231  213  312
		// 132  123  213
		//  ..X [ordered] => .. [ordered X]
		//   or ..Y [order <X> ed]
		int size = (int)num.size();
		int biggest = num[size - 1];
		for (int i = size - 2; i >= 0; i--) {
			int x = num[i];
			if (x < biggest) { // ..X [ordered] => ..Y [order <X> ed]
				sort(num.begin() + i + 1, num.end());
				int j = i + 1;
				while (num[j] <= x) {
					j++;
				}
				swap(num[i], num[j]);
				return;
			}
			else {
				biggest = x; // ..X [ordered] => .. [ordered X]
			}
		}
		sort(num.begin(), num.end());
	}
	void test() {
		vector<vector<int>> tests = {
				{ 1, 2, 3 },
				{ 3, 2, 1 },
				{ 1, 1, 5 },
				{ 2, 3, 1 },
				{ 1, 3, 2 },
				{ 1 }
		};
		for (auto v : tests) {
			nextPermutation(v);
			for (int x : v) {
				cout << x << ' ';
			}
			cout << endl;
		}
	}
};
