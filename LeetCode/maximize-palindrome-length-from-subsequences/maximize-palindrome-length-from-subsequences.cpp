// Source: https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/

class Solution {
public:
    int longestPalindrome(std::string word1, std::string word2) {
        std::string s = word1 + word2;
        int n = s.size();
        int m = word1.size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        int result = 0;

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    // Ensure palindrome uses at least one character from each word
                    if (i < m && j >= m) {
                        result = std::max(result, dp[i][j]);
                    }
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return result;
    }
};
