// source: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for (auto& pair : adjacentPairs) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }

        // Find one of the ends (element with only one neighbor)
        int start;
        for (auto& [node, neighbors] : graph) {
            if (neighbors.size() == 1) {
                start = node;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;
        vector<int> result(n);
        result[0] = start;
        result[1] = graph[start][0];

        for (int i = 2; i < n; ++i) {
            auto& prev = result[i - 2];
            auto& curr = result[i - 1];
            for (int neighbor : graph[curr]) {
                if (neighbor != prev) {
                    result[i] = neighbor;
                    break;
                }
            }
        }

        return result;
    }
};
