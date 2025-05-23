
// Source: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/
// Description: Given your current location (x, y) and a list of points, return the index of the valid point
// (same x or y coordinate) with the smallest Manhattan distance. If multiple, return the smallest index.
// If none are valid, return -1.

#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int nearestValidPoint(int x, int y, const vector<vector<int>>& points) {
        int bestIdx = -1;
        int bestDist = INT_MAX;
        for (int i = 0; i < (int)points.size(); ++i) {
            int xi = points[i][0], yi = points[i][1];
            // Check validity: same x or same y
            if (xi != x && yi != y) continue;
            int dist = abs(x - xi) + abs(y - yi);
            if (dist < bestDist) {
                bestDist = dist;
                bestIdx = i;
            }
        }
        return bestIdx;
    }
};
