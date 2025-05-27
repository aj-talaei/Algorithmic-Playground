// Problem: Integer Break
// URL: https://leetcode.com/problems/integer-break/
// Given a positive integer n (n ≥ 2), break it into the sum of at least two positive integers and maximize the product of those integers.

#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        int result = 1;
        // Greedily break off 3's while n > 4
        while (n > 4) {
            result *= 3;
            n -= 3;
        }
        // Multiply the remainder
        result *= n;
        
        return result;
    }
};
