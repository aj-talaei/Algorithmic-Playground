// Source : https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;

        for (const auto& q : queries) {
            int count = 0;
            int cx = q[0], cy = q[1], r = q[2];
            int rSquared = r * r;

            for (const auto& p : points) {
                int dx = p[0] - cx;
                int dy = p[1] - cy;
                if (dx * dx + dy * dy <= rSquared) {
                    ++count;
                }
            }

            result.push_back(count);
        }

        return result;
    }
};
