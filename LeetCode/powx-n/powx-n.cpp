// Source : https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp) {
            if (exp & 1) result *= x;
            x *= x;
            exp >>= 1;
        }

        return result;
    }
};
