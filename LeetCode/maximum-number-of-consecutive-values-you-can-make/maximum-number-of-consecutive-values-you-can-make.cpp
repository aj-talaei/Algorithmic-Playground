// Source: https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int maxReachable = 1;  // We can always make 0

        for (int coin : coins) {
            if (coin > maxReachable) break;
            maxReachable += coin;
        }

        return maxReachable;
    }
};
