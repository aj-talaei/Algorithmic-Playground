// LeetCode: https://leetcode.com/problems/largest-number-after-mutating-substring/

// Problem:
// Replace a single contiguous substring of `num` using a digit mapping `change` to form
// the lexicographically largest number possible.

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool started = false;

        for (int i = 0; i < num.size(); ++i) {
            int digit = num[i] - '0';
            int mapped = change[digit];

            if (mapped > digit) {
                num[i] = mapped + '0';
                started = true;
            } else if (mapped < digit && started) {
                // Once mutation starts, stop at the first drop
                break;
            }
        }

        return num;
    }
};
