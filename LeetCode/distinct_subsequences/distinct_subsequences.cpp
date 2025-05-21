// Source: https://leetcode.com/problems/distinct-subsequences/
// Description: Given strings S and T, count how many distinct subsequences of S equal T.

#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(const std::string& S, const std::string& T) {
        int n = S.size(), m = T.size();
        // dp[j] = number of ways to form T[0..j-1] from processed prefix of S
        // Use unsigned long long to avoid signed overflow
        std::vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;  // empty T

        for (int i = 0; i < n; ++i) {
            // iterate backwards so we reuse the same array
            for (int j = m; j >= 1; --j) {
                if (S[i] == T[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        // The result is guaranteed to fit in a 32-bit signed int by problem constraints
        return static_cast<int>(dp[m]);
    }
};
