class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // https://oj.leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
        //
        // Say you have an array for which the i-th element is the price of a given stock on day i.
        // Design an algorithm to find the maximum profit. You may complete as many transactions as 
        // you like (ie, buy one and sell one share of the stock multiple times). However, you may 
        // not engage in multiple transactions at the same time (ie, you must sell the stock before 
        // you buy again).
        
        // Consider: 
        //  - at any given time, i can have at most one stock in hand
        //  - in the end, i should have zero stock in hand
        //  - i should not buy on the last day
        //
        // Draw a trend graph, the max profit is by adding all going-up segments together. To do so,
        // I can either locate the start and end of the going-up segment, or simpler, add every one-
        // day 'up' segment. This is because consecutive 'up' segments:
        //   { day 1: buy, day 2: sell & buy, day 3: sell & buy, day 4: sell }
        //   is equal to { day 1: buy, day 4: sell }
        
        int size = (int)prices.size();
        if (size == 0) { return 0; }
        int profit = 0;
        for (int i = 1; i < size; i++) {
            int delta = prices[i] - prices[i-1];
            profit += (delta > 0 ? delta : 0);
        }
        return profit;
    }
};
