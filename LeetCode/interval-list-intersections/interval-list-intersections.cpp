// Problem: Interval List Intersections
// URL: https://leetcode.com/problems/interval-list-intersections/
// Given two lists of disjoint, sorted intervals A and B (each represented as vector<int> {start, end}),
// return their intersections in the same format.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size()) {
            int lo = max(A[i][0], B[j][0]);
            int hi = min(A[i][1], B[j][1]);
            if (lo <= hi) {
                result.push_back({lo, hi});
            }
            // Advance the interval with the smaller endpoint
            if (A[i][1] < B[j][1]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
};
