// Source : https://leetcode.com/problems/perfect-squares/

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        // Static cache to support reuse across calls
        static vector<int> dp = {0};

        while (dp.size() <= n) {
            int i = dp.size();
            int minCount = INT_MAX;

            for (int j = 1; j * j <= i; ++j) {
                minCount = min(minCount, dp[i - j * j] + 1);
            }

            dp.push_back(minCount);
        }

        return dp[n];
    }
};
