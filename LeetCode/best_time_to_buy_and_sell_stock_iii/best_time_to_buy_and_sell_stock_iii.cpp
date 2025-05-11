// Problem: Best Time to Buy and Sell Stock III
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Difficulty: Hard
// Author: Amir Javid Talaei
//
// You are given an array prices where prices[i] is the price of a given stock on the i-th day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
// Example:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6
//
// Constraints:
// - 1 <= prices.length <= 10^5
// - 0 <= prices[i] <= 10^5

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        vector<int> forward(n, 0);   // Max profit for one transaction [0..i]
        vector<int> backward(n, 0);  // Max profit for one transaction [i..n-1]

        int minPrice = prices[0];
        for (int i = 1; i < n; ++i) {
            forward[i] = max(forward[i - 1], prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }

        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            backward[i] = max(backward[i + 1], maxPrice - prices[i]);
            maxPrice = max(maxPrice, prices[i]);
        }

        int maxProfit = 0;
        for (int i = 0; i < n; ++i) {
            maxProfit = max(maxProfit, forward[i] + backward[i]);
        }

        return maxProfit;
    }
};
