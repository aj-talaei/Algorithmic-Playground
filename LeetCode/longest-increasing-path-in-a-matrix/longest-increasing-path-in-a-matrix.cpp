// Source : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> memo(m, std::vector<int>(n, 0));
        int maxPath = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                maxPath = std::max(maxPath, dfs(matrix, memo, i, j));

        return maxPath;
    }

private:
    int dfs(const std::vector<std::vector<int>>& matrix,
            std::vector<std::vector<int>>& memo,
            int i, int j) {
        
        if (memo[i][j] != 0) return memo[i][j];

        static const std::vector<std::pair<int, int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int maxLen = 1;

        for (const auto& [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[x][y] > matrix[i][j]) {
                maxLen = std::max(maxLen, 1 + dfs(matrix, memo, x, y));
            }
        }

        memo[i][j] = maxLen;
        return maxLen;
    }
};
