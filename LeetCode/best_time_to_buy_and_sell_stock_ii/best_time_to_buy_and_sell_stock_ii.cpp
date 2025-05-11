// Problem: Best Time to Buy and Sell Stock II
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time.
// However, you can buy it then immediately sell it on the same day.
//
// Find and return the maximum profit you can achieve.
//
// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 7
//
// Constraints:
// - 1 <= prices.length <= 3 * 10^4
// - 0 <= prices[i] <= 10^4

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            // If today's price is higher than yesterday's, we can profit
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
