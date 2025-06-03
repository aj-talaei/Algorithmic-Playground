// Problem: Minimum ASCII Delete Sum for Two Strings
// Source  : https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int minimumDeleteSum(std::string s1, std::string s2) {
        int m = s1.length(), n = s2.length();
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        // Initialize first row and column with ASCII deletion costs
        for (int i = 1; i <= m; ++i)
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        for (int j = 1; j <= n; ++j)
            dp[0][j] = dp[0][j - 1] + s2[j - 1];

        // Fill DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min(
                        dp[i - 1][j] + s1[i - 1],
                        dp[i][j - 1] + s2[j - 1]
                    );
                }
            }
        }

        return dp[m][n];
    }
};
