// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Author: Amir Javid Talaei
//
// You are given an array prices where prices[i] is the price of a given stock on the i-th day.
// You want to maximize your profit by choosing a single day to buy one stock and a different day in the future to sell that stock.
//
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
//
// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
//
// Constraints:
// - 1 <= prices.length <= 10^5
// - 0 <= prices[i] <= 10^4

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            // Track the lowest price so far
            minPrice = min(minPrice, price);
            // Calculate the profit if sold today
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
