// Source : https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        if (n <= 1) return n;

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;

        // Fill DP table from bottom up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    ++count;
                }
            }
        }

        return count;
    }
};
