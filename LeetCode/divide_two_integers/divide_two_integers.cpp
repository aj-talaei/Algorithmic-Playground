// Source: https://leetcode.com/problems/divide-two-integers/
// Description: Divide two integers without using multiplication, division, or mod operator. If overflow occurs, return INT_MAX.

#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        // Determine sign of result
        bool negative = (dividend < 0) ^ (divisor < 0);
        // Work with positive values
        long long dvd = dividend;
        long long dvs = divisor;
        dvd = dvd < 0 ? -dvd : dvd;
        dvs = dvs < 0 ? -dvs : dvs;
        
        long long result = 0;
        // Subtract shifted divisors
        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }
            dvd -= temp;
            result += multiple;
        }
        return negative ? -result : result;
    }
};
