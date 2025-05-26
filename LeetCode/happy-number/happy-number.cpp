// Problem: https://leetcode.com/problems/happy-number/
// A happy number is a number defined by the following process: 
// Starting with any positive integer, replace the number by the sum of the squares 
// of its digits, and repeat the process until the number equals 1 (a happy number), 
// or it loops endlessly in a cycle which does not include 1.

#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = sumOfSquares(n);
        }
        return n == 1;
    }

private:
    int sumOfSquares(int n) {
        int total = 0;
        while (n > 0) {
            int digit = n % 10;
            total += digit * digit;
            n /= 10;
        }
        return total;
    }
};
