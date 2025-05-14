// You are given coins of different denominations and a total amount of money `amount`. 
// Return the fewest number of coins that you need to make up that amount. If that amount 
// cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.
//
// Example:
// Input: coins = [1, 2, 5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
//
// Constraints:
// - 1 <= coins.length <= 12
// - 1 <= coins[i] <= 2^31 - 1
// - 0 <= amount <= 10^4

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = amount + 1;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == INF ? -1 : dp[amount];
    }
};
