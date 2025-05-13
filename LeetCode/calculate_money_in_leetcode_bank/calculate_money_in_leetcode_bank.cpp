// Problem: Calculate Money in Leetcode Bank
// Source: https://leetcode.com/problems/calculate-money-in-leetcode-bank/
//
// Description:
// Hercy deposits money in the Leetcode bank over a number of days.
// - On the 1st Monday, he deposits $1, and each subsequent day of the week he adds $1 more than the previous day.
// - On the next Monday, he deposits $1 more than the previous Monday, and continues the same pattern.
// Given `n` days, return the total money in the bank after `n` days.
//
// Example:
// Input: n = 10
// Output: 37
// Explanation: Week 1: 1+2+3+4+5+6+7 = 28, Week 2: 2+3+4 = 9 → total = 37

class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;

        int fullWeekSum = 1 + 2 + 3 + 4 + 5 + 6 + 7; // sum of one full week
        // Total from complete weeks:
        //   weeks * fullWeekSum + 7 * (0 + 1 + ... + weeks-1)
        int money = weeks * fullWeekSum + 7 * (weeks - 1) * weeks / 2;

        // Remaining days contribution
        //   Each remaining day adds weeks (as starting base) + (1 to days)
        money += days * weeks + days * (days + 1) / 2;

        return money;
    }
};
