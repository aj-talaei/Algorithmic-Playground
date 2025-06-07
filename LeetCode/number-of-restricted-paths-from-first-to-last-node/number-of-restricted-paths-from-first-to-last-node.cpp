// source: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/

class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        const int MOD = 1e9 + 7;

        // Build adjacency list
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Dijkstra to compute shortest distance from node `n` to every other node
        vector<int> dist(n + 1, INT_MAX);
        dist[n] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, n);

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto [v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        // Sort nodes by increasing distance to node `n`
        vector<int> nodes(n);
        iota(nodes.begin(), nodes.end(), 1);
        sort(nodes.begin(), nodes.end(), [&](int a, int b) {
            return dist[a] < dist[b];
        });

        // DP: count restricted paths
        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for (int u : nodes) {
            for (auto [v, _] : graph[u]) {
                if (dist[u] > dist[v]) {
                    dp[u] = (dp[u] + dp[v]) % MOD;
                }
            }
        }

        return dp[1];
    }
};
