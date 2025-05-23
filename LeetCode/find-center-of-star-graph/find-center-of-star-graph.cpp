// Source: https://leetcode.com/problems/find-center-of-star-graph/
// Description: Given edges of an undirected n-node star graph, return its center node.

#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(const vector<vector<int>>& edges) {
        // The center node appears in both of the first two edges.
        int u1 = edges[0][0], v1 = edges[0][1];
        int u2 = edges[1][0], v2 = edges[1][1];
        if (u1 == u2 || u1 == v2) return u1;
        return v1;
    }
};
