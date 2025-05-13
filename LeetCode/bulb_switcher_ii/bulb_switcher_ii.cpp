// Problem: Bulb Switcher II
// Source: https://leetcode.com/problems/bulb-switcher-ii/
//
// There are n lights initially turned on. You can perform exactly m operations.
// Each operation presses one of the 4 buttons:
//   1) Flip all lights
//   2) Flip lights with even numbers
//   3) Flip lights with odd numbers
//   4) Flip lights at positions (3k + 1)
// Return how many different light statuses are possible after m operations.
//
// Note: Due to overlapping effects between the 4 buttons, the number of unique
// outcomes is limited based on n and m.

class Solution {
public:
    int flipLights(int n, int m) {
        if (m == 0 || n == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return m == 1 ? 3 : 4;
        if (m == 1) return 4;
        return m == 2 ? 7 : 8;
    }
};
