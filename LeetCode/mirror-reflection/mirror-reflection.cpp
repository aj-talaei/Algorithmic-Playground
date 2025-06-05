// source: https://leetcode.com/problems/mirror-reflection/

class Solution {
public:
    int mirrorReflection(int p, int q) {
        int m = 1, n = 1;
        while ((m * p) % q != 0) ++m;
        n = (m * p) / q;

        if (m % 2 == 0) return 0;
        if (n % 2 == 0) return 2;
        return 1;
    }
};
