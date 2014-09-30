class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock/
        //
        // Say you have an array for which the ith element is the price of a given stock on day i.
        // If you were only permitted to complete at most one transaction (ie, buy one and sell 
        // one share of the stock), design an algorithm to find the maximum profit.
        
        int size = (int)prices.size();
        if (size == 0) { return 0; }
        int profit = 0;
        int low = prices[0];
        for (int i = 1; i < size; i++) {
            int price = prices[i];
            int newLow = min(low, price);
            profit = max(profit, price - low);
            low = newLow;
        }
        return profit;
    }
};
