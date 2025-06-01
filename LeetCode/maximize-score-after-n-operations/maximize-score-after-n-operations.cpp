// Source: https://leetcode.com/problems/maximize-score-after-n-operations/

class Solution {
public:
    int maxScore(std::vector<int>& nums) {
        int n = nums.size();
        int totalPairs = n / 2;

        std::vector<std::vector<int>> gcdMatrix(n, std::vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                gcdMatrix[i][j] = std::gcd(nums[i], nums[j]);
            }
        }

        std::unordered_map<int, int> memo;
        return dfs(gcdMatrix, 0, n, totalPairs, memo);
    }

private:
    int dfs(const std::vector<std::vector<int>>& gcdMatrix, int mask, int n, int step,
            std::unordered_map<int, int>& memo) {
        if (memo.count(mask)) return memo[mask];
        if (step == 0) return 0;

        int maxScore = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (mask & (1 << i)) continue;
            for (int j = i + 1; j < n; ++j) {
                if (mask & (1 << j)) continue;
                int newMask = mask | (1 << i) | (1 << j);
                int score = step * gcdMatrix[i][j] + dfs(gcdMatrix, newMask, n, step - 1, memo);
                maxScore = std::max(maxScore, score);
            }
        }

        return memo[mask] = maxScore;
    }
};
