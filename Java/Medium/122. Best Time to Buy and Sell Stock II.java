/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
*/

class Solution {    // 1ms 45mb
    public int maxProfit(int[] prices) {
        if (prices == null || prices.length < 2)
            return 0;
        int profit = 0;
        for (int i = 1; i < prices.length; i++)
            if (prices[i] > prices[i - 1])
                profit += prices[i] - prices[i - 1];
        return profit;
    }

    public static class Main {
        public static void main(String[] args) {
            Solution test = new Solution();
            int[] prices = {7, 1, 5, 3, 6, 4};
            System.out.println(test.maxProfit(prices));
        }
    }
}