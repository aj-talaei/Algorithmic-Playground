// Problem: Interleaving String
// URL: https://leetcode.com/problems/interleaving-string/
// Given strings s1, s2, and s3, return true if s3 is formed by an interleaving of s1 and s2.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if (n1 + n2 != n3) return false;
        
        // dp[i][j] = whether s3[0..i+j-1] can be formed by interleaving
        //             s1[0..i-1] and s2[0..j-1]
        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[0][0] = true;
        
        // Initialize first column (using only s1)
        for (int i = 1; i <= n1; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        // Initialize first row (using only s2)
        for (int j = 1; j <= n2; ++j) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }
        
        // Fill the DP table
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                char c = s3[i + j - 1];
                dp[i][j] = (dp[i-1][j] && s1[i-1] == c)
                        || (dp[i][j-1] && s2[j-1] == c);
            }
        }
        
        return dp[n1][n2];
    }
};
