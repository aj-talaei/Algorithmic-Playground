// source: https://leetcode.com/problems/nth-digit/

class Solution {
public:
    int findNthDigit(int n) {
        long len = 1, count = 9, start = 1;

        // Find the digit length group that contains the nth digit
        while (n > len * count) {
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }

        // Find the actual number containing the nth digit
        start += (n - 1) / len;
        string num = to_string(start);

        return num[(n - 1) % len] - '0';
    }
};
