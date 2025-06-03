// Problem: Minimum Cost For Tickets
// Source  : https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
        const int n = days.size();
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {
            // Option 1: Buy 1-day pass for today
            dp[i] = dp[i - 1] + costs[0];

            // Option 2: Buy 7-day or 30-day pass from an earlier day
            for (int j = i - 1; j >= 0; --j) {
                int gap = days[i - 1] - days[j];
                if (gap < 7) {
                    dp[i] = std::min(dp[i], dp[j] + costs[1]);
                }
                if (gap < 30) {
                    dp[i] = std::min(dp[i], dp[j] + costs[2]);
                }
                if (gap >= 30) {
                    break; // No need to check earlier days
                }
            }
        }

        return dp[n];
    }
};
