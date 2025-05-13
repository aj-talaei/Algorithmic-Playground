/*
 * Leetcode Problem: Check if Number is a Sum of Powers of Three
 *
 * Given an integer n, return true if it can be represented as the sum of distinct powers of three.
 * A number x is a power of three if there exists an integer k such that x == 3^k.
 *
 * Example:
 * Input: n = 12 → Output: true  (12 = 3^1 + 3^2)
 * Input: n = 91 → Output: true  (91 = 3^0 + 3^1 + 3^4)
 * Input: n = 21 → Output: false
 */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        // Convert n to base-3 and check if all digits are 0 or 1
        while (n > 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }
        return true;
    }
};
