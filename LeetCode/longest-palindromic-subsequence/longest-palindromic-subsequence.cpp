// Source : https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int longestPalindromeSubseq(const std::string& s) {
        int n = s.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
