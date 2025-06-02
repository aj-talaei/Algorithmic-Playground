// Source: https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        // Sort a, b, c so that a <= b <= c
        vector<int> piles = {a, b, c};
        sort(piles.begin(), piles.end());

        int sum = piles[0] + piles[1] + piles[2];

        // If the largest pile is greater than the sum of the other two,
        // we can only make as many moves as there are stones in the smaller two.
        if (piles[2] >= piles[0] + piles[1]) {
            return piles[0] + piles[1];
        }

        // Otherwise, we can always pair two non-empty piles.
        return sum / 2;
    }
};
