// Source: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/
// Description: Given two eggs and a building with n floors, compute the minimum number of moves 
// needed to determine the highest floor f from which an egg can be dropped without breaking.

#include <cmath>

class Solution {
public:
    int twoEggDrop(int n) {
        // We need the smallest k such that 1 + 2 + ... + k >= n,
        // i.e. k*(k+1)/2 >= n. Solve k from the quadratic inequality.
        // k = ceil((sqrt(1 + 8n) - 1) / 2).
        return static_cast<int>(std::ceil((std::sqrt(1.0 + 8.0 * n) - 1) / 2));
    }
};
