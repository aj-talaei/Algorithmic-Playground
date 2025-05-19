// Problem: Count Numbers With Unique Digits
// Given a non-negative integer n, count all numbers x in the range 0 ≤ x < 10^n
// such that each digit of x is unique.

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;      // for n = 0, only “0”
        int count = 9;    // number of choices for the first digit (1–9)
        for (int i = 1; i <= n; ++i) {
            ans += count;
            count *= (10 - i);
        }
        return ans;
    }
};
