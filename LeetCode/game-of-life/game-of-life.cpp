// Source: https://leetcode.com/problems/game-of-life/
// Description: Given an m×n board of 0/1 cells, compute the next state in-place per Conway’s rules:
//              - Live cell (1) with <2 or >3 live neighbors dies.
//              - Live cell with 2 or 3 neighbors stays alive.
//              - Dead cell (0) with exactly 3 neighbors becomes alive.

#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        // Use 2nd bit to store next state:
        //   current in bit0, next in bit1.
        auto countLive = [&](int i, int j) {
            int cnt = 0;
            for (int x = max(i-1,0); x <= min(i+1,m-1); ++x)
                for (int y = max(j-1,0); y <= min(j+1,n-1); ++y)
                    cnt += board[x][y] & 1;
            return cnt - (board[i][j] & 1);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int liveNeighbors = countLive(i, j);
                if ((board[i][j] & 1) == 1) {
                    // stays alive if 2 or 3 neighbors
                    if (liveNeighbors == 2 || liveNeighbors == 3)
                        board[i][j] |= 2;
                } else {
                    // dead becomes live if exactly 3 neighbors
                    if (liveNeighbors == 3)
                        board[i][j] |= 2;
                }
            }
        }
        // shift to next state
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};
