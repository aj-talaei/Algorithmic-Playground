// Problem: Broken Calculator
// Source: https://leetcode.com/problems/broken-calculator/
//
// You are given two integers X and Y. Starting from X, you can perform two operations:
//   - Double: Multiply the number by 2
//   - Decrement: Subtract 1
//
// Return the minimum number of operations to display Y starting from X.

class Solution {
public:
    int brokenCalc(int X, int Y) {
        if (X >= Y) return X - Y;
        if (Y % 2 == 0) return brokenCalc(X, Y / 2) + 1;
        return brokenCalc(X, Y + 1) + 1;
    }
};
