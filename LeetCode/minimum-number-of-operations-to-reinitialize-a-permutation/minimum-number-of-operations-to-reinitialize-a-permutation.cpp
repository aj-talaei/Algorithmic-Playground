// source: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/

class Solution {
public:
    int reinitializePermutation(int n) {
        int pos = 1, count = 0;
        do {
            if (pos % 2 == 0)
                pos /= 2;
            else
                pos = n / 2 + (pos - 1) / 2;
            ++count;
        } while (pos != 1);
        return count;
    }
};
