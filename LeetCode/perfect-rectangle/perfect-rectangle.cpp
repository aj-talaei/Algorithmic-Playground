// Source : https://leetcode.com/problems/perfect-rectangle/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using Point = pair<int, int>;

        struct PointHash {
            size_t operator()(const Point& p) const {
                return hash<long long>()(((long long)p.first << 32) | (unsigned int)p.second);
            }
        };

        unordered_set<Point, PointHash> points;

        int minX = INT_MAX, minY = INT_MAX, maxX = INT_MIN, maxY = INT_MIN;
        long long actualArea = 0;

        for (const auto& rect : rectangles) {
            int x1 = rect[0], y1 = rect[1], x2 = rect[2], y2 = rect[3];

            minX = min(minX, x1);
            minY = min(minY, y1);
            maxX = max(maxX, x2);
            maxY = max(maxY, y2);

            actualArea += static_cast<long long>(x2 - x1) * (y2 - y1);

            Point corners[4] = {{x1, y1}, {x1, y2}, {x2, y1}, {x2, y2}};
            for (const Point& p : corners) {
                if (!points.insert(p).second) {
                    points.erase(p); // Remove if already present (shared corner)
                }
            }
        }

        long long expectedArea = static_cast<long long>(maxX - minX) * (maxY - minY);
        if (actualArea != expectedArea || points.size() != 4) return false;

        return points.count({minX, minY}) &&
               points.count({minX, maxY}) &&
               points.count({maxX, minY}) &&
               points.count({maxX, maxY});
    }
};
