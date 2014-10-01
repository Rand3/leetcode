class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
		//
		// Say you have an array for which the i-th element is the price of a given stock on day i.
		// Design an algorithm to find the maximum profit. You may complete at most two transactions.
		// Note: You may not engage in multiple transactions at the same time (ie, you must sell the 
		// stock before you buy again).

		// Read: 
		//  - at any given time, i can have at most one share of stock in hand
		//  - i can do buy/sell at most twice
		//  - each time, i can only buy or sell one share of stock
		// The problem is to find two highest 'going-up' segments

		// Solution: DP for first buy/sell, and then reverse DP for second buy/sell
		// f(k) := max profit for first k days, if i can do buy/sell only *once*
		// f(k) = max( f(k-1), price[k] - low )
		int size = (int)prices.size();
		if (size <= 1) { return 0; }
		vector<int> profit(size);
		int low = prices[0];
		profit[0] = 0;
		for (int i = 1; i < size; i++) {
			int price = prices[i];
			int newLow = min(low, price);
			profit[i] = max(profit[i - 1], price - low);
			low = newLow;
		}
		int high = prices[size - 1];
		int result = profit[size - 1];
		int profit2 = 0;
		for (int i = size - 2; i >= 0; i--) {
			int price = prices[i];
			int newHigh = max(high, price);
			profit2 = max(profit2, high - price);
			high = newHigh;
			int profit1 = (i > 0 ? profit[i - 1] : 0);
			result = max(result, profit1 + profit2);
		}
		return result;
	}
};
