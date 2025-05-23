// Source: https://leetcode.com/problems/factorial-trailing-zeroes/
// Description: Count the number of trailing zeros in n! by summing floor(n/5) + floor(n/25) + floor(n/125) + ...

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;
            count += n;
        }
        return count;
    }
};
