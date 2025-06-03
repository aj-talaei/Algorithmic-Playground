// Problem: Minimum Degree of a Connected Trio in a Graph
// Source  : https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/

class Solution {
public:
    int minTrioDegree(int n, std::vector<std::vector<int>>& edges) {
        // Build adjacency matrix and degree array
        std::vector<std::vector<bool>> connected(n + 1, std::vector<bool>(n + 1, false));
        std::vector<int> degree(n + 1, 0);

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            connected[u][v] = true;
            connected[v][u] = true;
            degree[u]++;
            degree[v]++;
        }

        int minDegree = INT_MAX;

        // Try all possible triplets
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!connected[i][j]) continue;
                for (int k = j + 1; k <= n; ++k) {
                    if (connected[i][k] && connected[j][k]) {
                        int trioDegree = degree[i] + degree[j] + degree[k] - 6;
                        minDegree = std::min(minDegree, trioDegree);
                    }
                }
            }
        }

        return minDegree == INT_MAX ? -1 : minDegree;
    }
};
