// Source: https://leetcode.com/problems/count-pairs-of-nodes/
// Description:
//   Given an undirected graph of n nodes (1…n) with possibly repeated edges, for each query q
//   count the number of distinct node‐pairs (u, v), u < v, such that the total number of edges
//   incident to u or v (their degrees summed) is strictly greater than q. Repeated edges between
//   the same two nodes only increase their shared count and must be handled to avoid overcounting.

#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        // 1) Compute degrees and count shared edges
        vector<int> degree(n, 0);
        // key = u * n + v (u < v), value = number of edges between u and v
        unordered_map<int,int> shared;
        shared.reserve(edges.size());
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            degree[u]++;
            degree[v]++;
            if (u > v) std::swap(u,v);
            shared[u * n + v]++;
        }
        
        // 2) Sort degrees for two-pointer counting
        vector<int> sorted_deg = degree;
        sort(sorted_deg.begin(), sorted_deg.end());
        
        int m = queries.size();
        vector<int> answer(m);
        
        // 3) For each query, count initial pairs by two-pointer on sorted degrees
        for (int qi = 0; qi < m; ++qi) {
            int q = queries[qi];
            long long cnt = 0;
            int l = 0, r = n - 1;
            while (l < r) {
                if (sorted_deg[l] + sorted_deg[r] > q) {
                    cnt += (r - l);
                    --r;
                } else {
                    ++l;
                }
            }
            
            // 4) Subtract overcounted pairs where shared edges push sum <= q
            for (auto& kv : shared) {
                int key = kv.first;
                int c   = kv.second;
                int u   = key / n;
                int v   = key % n;
                int sum = degree[u] + degree[v];
                // counted if sum > q, but should exclude if sum - c <= q
                if (sum > q && sum - c <= q) {
                    --cnt;
                }
            }
            
            answer[qi] = cnt;
        }
        
        return answer;
    }
};
