// Problem: Best Time to Buy and Sell Stock IV
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// Difficulty: Hard
// Author: Amir Javid Talaei
//
// You are given an integer k and an array prices where prices[i] is the price of a given stock on the i-th day.
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
// Example:
// Input: k = 2, prices = [2,4,1]
// Output: 2
//
// Constraints:
// - 0 <= k <= 100
// - 0 <= prices.length <= 1000
// - 0 <= prices[i] <= 1000

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        // Special case: large k means unlimited transactions allowed (use greedy)
        if (k >= n / 2) {
            int totalProfit = 0;
            for (int i = 1; i < n; ++i) {
                totalProfit += max(0, prices[i] - prices[i - 1]);
            }
            return totalProfit;
        }

        // DP table: profits[t][d] = max profit using at most t transactions by day d
        vector<vector<int>> profits(k + 1, vector<int>(n + 1, 0));

        for (int t = 1; t <= k; ++t) {
            int maxDiff = profits[t - 1][0] - prices[0];
            for (int d = 1; d <= n; ++d) {
                profits[t][d] = max(profits[t][d - 1], maxDiff + prices[d - 1]);
                if (d < n) {
                    maxDiff = max(maxDiff, profits[t - 1][d] - prices[d]);
                }
            }
        }

        return profits[k][n];
    }
};
