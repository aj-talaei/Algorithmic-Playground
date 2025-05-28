// LeetCode: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> inDegree(n, 0);

        // Build graph and in-degree
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            ++inDegree[edge[1]];
        }

        queue<int> q;
        vector<vector<int>> colorCount(n, vector<int>(26, 0));

        // Initialize queue with nodes having 0 in-degree
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) q.push(i);
        }

        int visited = 0, maxValue = 0;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            ++visited;

            int colorIdx = colors[u] - 'a';
            colorCount[u][colorIdx]++;
            maxValue = max(maxValue, colorCount[u][colorIdx]);

            for (int v : graph[u]) {
                for (int c = 0; c < 26; ++c) {
                    colorCount[v][c] = max(colorCount[v][c], colorCount[u][c]);
                }

                if (--inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visited == n ? maxValue : -1; // If not all nodes visited → cycle detected
    }
};
