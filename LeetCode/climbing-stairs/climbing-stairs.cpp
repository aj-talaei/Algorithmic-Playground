/*
 * Leetcode Problem: Climbing Stairs
 *
 * You are climbing a staircase. It takes `n` steps to reach the top.
 * Each time you can either climb 1 or 2 steps.
 * Return the number of distinct ways to reach the top.
 *
 * Example:
 * Input: n = 3
 * Output: 3
 * Explanation: 1+1+1, 1+2, 2+1
 *
 * This is a classic dynamic programming problem, equivalent to computing the nth Fibonacci number.
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;
        int prev = 2, curr = 3;
        for (int i = 4; i <= n; i++) {
            int temp = prev + curr;
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
