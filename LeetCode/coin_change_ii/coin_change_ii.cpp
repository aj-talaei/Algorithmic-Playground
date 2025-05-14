/*
 * Problem: Coin Change II
 * Link   : https://leetcode.com/problems/coin-change-2/
 *
 * Description:
 * You are given coins of different denominations and a total amount of money.
 * Return the number of combinations that make up that amount.
 * You may assume that you have infinite number of each kind of coin.
 *
 * Example:
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: There are four ways to make up the amount:
 *   5=5
 *   5=2+2+1
 *   5=2+1+1+1
 *   5=1+1+1+1+1
 *
 * Constraints:
 *   - 0 <= amount <= 5000
 *   - 1 <= coin <= 5000
 *   - Number of coins < 500
 *   - The answer fits in a signed 32-bit integer
 */

#include <iostream>
#include <vector>
#include <numeric>

class Solution {
public:
    int change(int amount, std::vector<int>& coins) {
        // If the target amount is odd and all coins are even, there are no ways to make change.
        if (amount % 2 != 0) {
            bool all_even = true;
            for (int coin : coins) {
                if (coin % 2 != 0) {
                    all_even = false;
                    break;
                }
            }
            if (all_even) {
                return 0;
            }
        }

        std::vector<long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                // Check for potential overflow before addition
                if (dp[i] > std::numeric_limits<long long>::max() - dp[i - coin]) {
                    return -1;
                }
                dp[i] += dp[i - coin];
            }
        }

        return static_cast<int>(dp[amount]);
    }
};