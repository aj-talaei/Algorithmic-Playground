// Source: https://leetcode.com/problems/minimum-height-trees/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<unordered_set<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (graph[i].size() == 1) leaves.push_back(i);
        }

        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();
            vector<int> newLeaves;
            for (int leaf : leaves) {
                int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                if (graph[neighbor].size() == 1) newLeaves.push_back(neighbor);
            }
            leaves = newLeaves;
        }

        return leaves;
    }
};
