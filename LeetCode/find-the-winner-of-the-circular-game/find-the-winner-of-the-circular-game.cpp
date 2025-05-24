// Source: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
// Description: Given `n` friends numbered 1 to n in a circle, eliminate every k-th friend
//              (counting starts at the current position and wraps around) until only one remains.
//              Return the winner's number.

class Solution {
public:
    int findTheWinner(int n, int k) {
        // Josephus problem iterative solution
        int winnerIndex = 0;  // using 0-based indexing
        for (int size = 1; size <= n; ++size) {
            winnerIndex = (winnerIndex + k) % size;
        }
        return winnerIndex + 1;  // convert to 1-based numbering
    }
};

