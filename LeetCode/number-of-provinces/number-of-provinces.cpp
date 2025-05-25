// Source: https://leetcode.com/problems/friend-circles/
// Description: Given an N×N adjacency matrix `M` where M[i][j] = 1 indicates a direct friendship
//              between student i and j (and friendships are mutual), return the number of friend
//              circles (connected components under transitive closure).

#include <vector>
using namespace std;

class Solution {
public:
    int findCircleNum(const vector<vector<int>>& M) {
        int n = M.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
        
        // Union every pair of direct friends
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (M[i][j] == 1) {
                    unite(i, j);
                }
            }
        }
        
        // Count distinct roots
        int circles = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                ++circles;
            }
        }
        return circles;
    }

private:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx == ry) return;
        // union by rank
        if (rank[rx] < rank[ry]) {
            parent[rx] = ry;
        } else if (rank[ry] < rank[rx]) {
            parent[ry] = rx;
        } else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
};


