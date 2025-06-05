// source: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        // Pass 1: left to right
        int moves = 0, balls = 0;
        for (int i = 0; i < n; ++i) {
            result[i] += moves;
            if (boxes[i] == '1') ++balls;
            moves += balls;
        }

        // Pass 2: right to left
        moves = 0;
        balls = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += moves;
            if (boxes[i] == '1') ++balls;
            moves += balls;
        }

        return result;
    }
};
