// source: https://leetcode.com/problems/number-of-different-subsequences-gcds/

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        const int MAX = 200000;
        vector<bool> present(MAX + 1, false);
        for (int num : nums) present[num] = true;

        int count = 0;
        for (int i = 1; i <= MAX; ++i) {
            int currGCD = 0;
            for (int j = i; j <= MAX; j += i) {
                if (present[j]) {
                    currGCD = gcd(currGCD, j);
                    if (currGCD == i) break;
                }
            }
            if (currGCD == i) ++count;
        }
        return count;
    }

private:
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
