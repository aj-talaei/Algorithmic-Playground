// Source: https://leetcode.com/problems/decode-ways/
// Description: Given a digit-only string, return the number of ways to decode it
// using the mapping 'A'->1, 'B'->2, …, 'Z'->26.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(const string& s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        // dp[i] = number of ways to decode the first i characters
        vector<int> dp(n+1, 0);
        dp[0] = 1;  // empty string
        dp[1] = 1;  // first char is non-'0'
        
        for (int i = 2; i <= n; ++i) {
            // Single-digit decode (must be '1'..'9')
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            // Two-digit decode (10..26)
            int two = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if (two >= 10 && two <= 26) {
                dp[i] += dp[i-2];
            }
        }
        
        return dp[n];
    }
};
