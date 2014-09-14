class Solution {
public:
	int candy(vector<int> &ratings) {
		// https://oj.leetcode.com/problems/candy/
		//
		// There are N children standing in a line. Each child is assigned a rating value.
		// You are giving candies to these children subjected to the following requirements:
		//   Each child must have at least one candy.
		//   Children with a higher rating get more candies than their neighbors.
		// What is the minimum candies you must give? 
		//
		int size = ratings.size();
		vector<int> indexes(size);
		for (int i = 0; i < size; i++) {
			indexes[i] = i;
		}
		sort(indexes.begin(), indexes.end(), sortIndex(ratings));
		vector<int> result(size, 0);
		int total = 0;
		for (int i = 0; i < size; i++) {
			int index = indexes[i];
			int left = (index == 0 || ratings[index - 1] >= ratings[index]) ? 1 : result[index - 1] + 1;
			int right = (index == size - 1 || ratings[index + 1] >= ratings[index]) ? 1 : result[index + 1] + 1;
			result[index] = max(left, right);
			total += result[index];
		}
		return total;
	}
	class sortIndex {
		vector<int> &values;
	public:
		sortIndex(vector<int> &v) : values(v) {}
		bool operator()(int i, int j) {
			return values[i] < values[j];
		}
	};
	void test() {
		vector<int> ratings = { 3, 10, 2, 2, 3 };
		int candies = candy(ratings);
		for (int n : ratings) {
			cout << n << ' ';
		}
		cout << endl << candies << endl;
	}
};
