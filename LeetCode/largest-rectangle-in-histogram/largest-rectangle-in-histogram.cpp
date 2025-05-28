// LeetCode: https://leetcode.com/problems/largest-rectangle-in-histogram/

// Problem:
// Given an array of bar heights, return the area of the largest rectangle that can be formed.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // Sentinel to process all bars
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()]; st.pop();
                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * w);
            }
            st.push(i);
        }

        return maxArea;
    }
};
