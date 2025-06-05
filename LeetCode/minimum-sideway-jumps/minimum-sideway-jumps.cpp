// source: https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        const int INF = n + 1;
        vector<int> dp = {1, 0, 1};  // lanes 1, 2, 3 → 0-indexed

        for (int i = 1; i < n; ++i) {
            // Set current lane to INF if there’s an obstacle
            for (int lane = 0; lane < 3; ++lane) {
                if (obstacles[i] == lane + 1) {
                    dp[lane] = INF;
                }
            }

            // Try side jumps for lanes without obstacles
            for (int lane = 0; lane < 3; ++lane) {
                if (obstacles[i] != lane + 1) {
                    dp[lane] = min(dp[lane], 
                                   (obstacles[i] != ((lane + 1) % 3) + 1 ? dp[(lane + 1) % 3] + 1 : INF));
                    dp[lane] = min(dp[lane], 
                                   (obstacles[i] != ((lane + 2) % 3) + 1 ? dp[(lane + 2) % 3] + 1 : INF));
                }
            }
        }

        return min({dp[0], dp[1], dp[2]});
    }
};
