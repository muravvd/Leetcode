/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices[i] < prices[i + 1]) {
                for (int j = i + 1; j < prices.size(); j++) {
                    if (prices[j] - prices[i] > profit) {
                        profit = prices[j] - prices[i];
                    }
                }
            }
        }
        return profit;
    }
};*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int profit = 0, low = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < low)
                low = prices[i];
            else if (prices[i] - low > profit)
                profit = prices[i] - low;
        }
        return profit;
    }
};

int main() {
    Solution test;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << test.maxProfit(prices);
    return 0;
};
