// Source: https://oj.leetcode.com/problems/dungeon-game/
// Description: Determine the knight's minimum initial health so that he can rescue the princess 
//              by only moving rightward or downward through a grid of rooms with health effects.

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = m ? dungeon[0].size() : 0;
        // dp[i][j] = min health needed upon entering cell (i,j)
        vector<vector<int>> dp(m, vector<int>(n));
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) {
                    // At the princess cell
                    dp[i][j] = max(1 - dungeon[i][j], 1);
                } else {
                    int needRight = (j + 1 < n)
                        ? max(dp[i][j + 1] - dungeon[i][j], 1)
                        : INT_MAX;
                    int needDown  = (i + 1 < m)
                        ? max(dp[i + 1][j] - dungeon[i][j], 1)
                        : INT_MAX;
                    dp[i][j] = min(needRight, needDown);
                }
            }
        }
        return dp[0][0];
    }
};
