// Source: https://leetcode.com/problems/maximize-number-of-nice-divisors/

class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    int maxNiceDivisors(int primeFactors) {
        if (primeFactors <= 3) return primeFactors;

        int quotient = primeFactors / 3;
        int remainder = primeFactors % 3;

        if (remainder == 0) {
            return modPow(3, quotient);
        } else if (remainder == 1) {
            // Instead of one '1', better to take one 3 out and use two 2s: 3^(q - 1) * 4
            return (modPow(3, quotient - 1) * 4) % MOD;
        } else {
            // remainder == 2
            return (modPow(3, quotient) * 2) % MOD;
        }
    }
};
