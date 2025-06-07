// source: https://leetcode.com/problems/number-of-digit-one/

class Solution {
public:
    int countDigitOne(int n) {
        long base = 1, count = 0, right = 0;
        int curr = 0, left = n;

        while (left > 0) {
            curr = left % 10;
            left /= 10;

            if (curr == 0) {
                count += left * base;
            } else if (curr == 1) {
                count += left * base + right + 1;
            } else {
                count += (left + 1) * base;
            }

            right += curr * base;
            base *= 10;
        }

        return count;
    }
};
