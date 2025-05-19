// Problem: Convert a Number to Hexadecimal
// Link: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
//
// Description:
// Given a 32-bit signed integer `num`, return its hexadecimal representation as a
// lowercase string. For negative numbers, use two’s complement. The result must not
// contain leading zeros (except for the single digit `"0"` when `num == 0`).
//
// Examples:
//   Input: 26      → Output: "1a"
//   Input: -1      → Output: "ffffffff"
//
// Constraints:
//   - `-2^31 ≤ num ≤ 2^31 - 1`
//   - You may not use built-in formatting functions to produce the hex string.
//
// Time Complexity: O(1) (at most 8 hex digits processed)
// Space Complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        static const char *hexDigits = "0123456789abcdef";
        unsigned int x = static_cast<unsigned int>(num);
        string s;
        while (x != 0) {
            s.push_back(hexDigits[x & 0xF]);
            x >>= 4;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
