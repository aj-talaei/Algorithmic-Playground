// LeetCode: https://leetcode.com/problems/largest-submatrix-with-rearrangements/

// Problem:
// After rearranging the columns in any order, find the largest submatrix (area) containing only 1s.

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; ++r) {
            // Update histogram heights
            for (int c = 0; c < cols; ++c) {
                height[c] = matrix[r][c] == 0 ? 0 : height[c] + 1;
            }

            // Copy and sort heights in descending order
            vector<int> sortedHeight = height;
            sort(sortedHeight.begin(), sortedHeight.end(), greater<int>());

            // Calculate maximum area for this row
            for (int i = 0; i < cols; ++i) {
                maxArea = max(maxArea, sortedHeight[i] * (i + 1));
            }
        }

        return maxArea;
    }
};
