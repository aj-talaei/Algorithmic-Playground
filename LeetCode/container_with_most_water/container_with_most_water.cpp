
// Problem: Container With Most Water
// Link: https://leetcode.com/problems/container-with-most-water/
//
// Description:
// Given an array of non-negative integers `height` where each element represents a vertical line
// at coordinate `(i, height[i])`, find two lines that together with the x-axis form a container
// such that the container holds the maximum amount of water. Return the maximum area.
//
// Constraints:
//  - 2 ≤ height.size() ≤ 10^5
//  - 0 ≤ height[i] ≤ 10^4

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int area = h * (right - left);
            max_area = max(max_area, area);
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return max_area;
    }
};
