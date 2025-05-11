// Problem: Bitwise AND of Numbers Range
// Source: https://leetcode.com/problems/bitwise-and-of-numbers-range/
//
// Given two integers `m` and `n`, return the bitwise AND of all numbers in the range [m, n], inclusive.
//
// Example:
// Input: m = 5, n = 7
// Output: 4

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shift = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};
