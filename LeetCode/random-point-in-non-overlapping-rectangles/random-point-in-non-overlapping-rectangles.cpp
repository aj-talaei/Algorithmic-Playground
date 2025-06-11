// Source : https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/

class Solution {
private:
    vector<vector<int>> rects;
    vector<int> prefixSums;

public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        int total = 0;
        for (const auto& r : rects) {
            int count = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            total += count;
            prefixSums.push_back(total);
        }
    }

    vector<int> pick() {
        int pointIndex = rand() % prefixSums.back();
        int rectIndex = upper_bound(prefixSums.begin(), prefixSums.end(), pointIndex) - prefixSums.begin();

        const auto& r = rects[rectIndex];
        int width = r[2] - r[0] + 1;
        int height = r[3] - r[1] + 1;
        int base = rectIndex == 0 ? 0 : prefixSums[rectIndex - 1];
        int offset = pointIndex - base;

        int x = r[0] + offset % width;
        int y = r[1] + offset / width;
        return {x, y};
    }
};
