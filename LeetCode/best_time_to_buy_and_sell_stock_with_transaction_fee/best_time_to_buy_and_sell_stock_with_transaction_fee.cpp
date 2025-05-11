// Problem: Best Time to Buy and Sell Stock with Transaction Fee
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
// Difficulty: Medium
// Author: Amir Javid Talaei
//
// You are given an array prices where prices[i] is the price of a given stock on the ith day,
// and an integer fee representing a transaction fee.
// Find the maximum profit you can achieve. You may complete as many transactions as you like,
// but you need to pay the transaction fee for each transaction.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
//
// Example:
// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
//
// Constraints:
// - 1 <= prices.length <= 5 * 10^4
// - 0 <= prices[i] < 50000
// - 0 <= fee < 50000

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = -prices[0]; // Max profit after buying stock
        int sell = 0;         // Max profit after selling stock

        for (int price : prices) {
            int prevBuy = buy;
            buy = max(buy, sell - price);             // Hold or buy
            sell = max(sell, prevBuy + price - fee);  // Hold or sell
        }

        return sell;
    }
};
