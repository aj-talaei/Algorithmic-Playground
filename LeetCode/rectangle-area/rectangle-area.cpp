// source: https://leetcode.com/problems/rectangle-area/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);

        int overlapWidth = max(0, min(C, G) - max(A, E));
        int overlapHeight = max(0, min(D, H) - max(B, F));
        int overlapArea = overlapWidth * overlapHeight;

        return area1 + area2 - overlapArea;
    }
};
