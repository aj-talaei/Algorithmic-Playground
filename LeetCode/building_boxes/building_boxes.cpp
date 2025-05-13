// Problem: Building Boxes
// Source: https://leetcode.com/problems/building-boxes/
//
// You are given an integer n representing the number of unit cube boxes.
// You must stack them in a cubic corner so that the structure is stable:
// each box placed on top must have all four vertical sides adjacent to
// either a wall or another box. Return the minimum number of boxes that
// must touch the floor to store all n boxes.

class Solution {
private:
    int total(long h) {
        return h * (h + 1) * (h + 2) / 6;
    }

public:
    int minimumBoxes(int n) {
        int left = 1, right = pow(6L * n, 1.0 / 3);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int t = total(mid);
            if (t == n) return mid * (mid + 1L) / 2;
            if (t < n) left = mid + 1;
            else right = mid - 1;
        }

        int height = right;
        int remaining = n - total(height);
        int base = height * (height + 1L) / 2;

        left = 1, right = sqrt(2 * remaining);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int s = mid * (mid + 1) / 2;
            if (s == remaining) return base + mid;
            if (s < remaining) left = mid + 1;
            else right = mid - 1;
        }

        return base + left;
    }
};
