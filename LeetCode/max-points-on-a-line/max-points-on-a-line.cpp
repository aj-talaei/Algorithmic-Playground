// Source : https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();

        int maxCount = 0;

        for (int i = 0; i < points.size(); ++i) {
            unordered_map<string, int> slopeCount;
            int duplicates = 1; // count self
            int localMax = 0;

            for (int j = i + 1; j < points.size(); ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    ++duplicates;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize the sign
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy); // for vertical lines
                }

                string slopeKey = to_string(dy) + "/" + to_string(dx);
                localMax = max(localMax, ++slopeCount[slopeKey]);
            }

            maxCount = max(maxCount, localMax + duplicates);
        }

        return maxCount;
    }

private:
    int gcd(int a, int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }
};
