// Problem: Integer Replacement
// URL: https://leetcode.com/problems/integer-replacement/
// Given a positive integer n, repeatedly replace it using:
// - n → n/2    if n is even
// - n → n+1 or n- → 1 if n is odd
// until it becomes 1; return the minimum number of replacements.

#include <climits>

class Solution {
public:
    int integerReplacement(int n) {
        long m = n;           // use long to avoid overflow when n = INT_MAX
        int steps = 0;
        
        while (m != 1) {
            if ((m & 1) == 0) {
                // even
                m >>= 1;
            } else {
                // odd: decide whether to increment or decrement
                // special-case 3 to avoid cycle: 3 → 2 → 1 (2 steps) is better than 3 → 4 → 2 → 1 (3 steps)
                if (m == 3 || (m & 3) == 1) {
                    m--;
                } else {
                    m++;
                }
            }
            ++steps;
        }
        
        return steps;
    }
};
