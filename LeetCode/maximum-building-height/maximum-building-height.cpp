// Source: https://leetcode.com/problems/maximum-building-height/

class Solution {
private:
    int getMaxBetween(const std::vector<int>& left, const std::vector<int>& right) {
        int dist = right[0] - left[0];
        int hDiff = std::abs(right[1] - left[1]);

        if (dist >= hDiff) {
            return std::min(left[1], right[1]) + (dist + hDiff) / 2;
        } else {
            return std::min(left[1], right[1]) + dist;
        }
    }

public:
    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        std::sort(restrictions.begin(), restrictions.end());

        int rSize = restrictions.size();

        // Forward pass: adjust heights for increasing indices
        for (int i = 1; i < rSize; ++i) {
            int maxReach = restrictions[i - 1][1] + (restrictions[i][0] - restrictions[i - 1][0]);
            restrictions[i][1] = std::min(restrictions[i][1], maxReach);
        }

        // Backward pass: adjust heights for decreasing indices
        for (int i = rSize - 2; i >= 0; --i) {
            int maxReach = restrictions[i + 1][1] + (restrictions[i + 1][0] - restrictions[i][0]);
            restrictions[i][1] = std::min(restrictions[i][1], maxReach);
        }

        // Compute maximum peak height between each adjacent pair of restrictions
        int result = 0;
        for (int i = 1; i < rSize; ++i) {
            result = std::max(result, getMaxBetween(restrictions[i - 1], restrictions[i]));
        }

        return result;
    }
};
