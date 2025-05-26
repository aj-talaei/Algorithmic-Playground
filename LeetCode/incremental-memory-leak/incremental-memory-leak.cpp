// Problem: https://leetcode.com/problems/incremental-memory-leak/
// At each second i (starting from 1), allocate i bits of memory to the stick with more memory available.
// If both have the same, allocate to memory1. The program crashes when neither has i bits available.
// Return [crashTime, memory1_remaining, memory2_remaining].

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int time = 1;
        while (true) {
            if (memory1 >= memory2) {
                if (memory1 < time) break;
                memory1 -= time;
            } else {
                if (memory2 < time) break;
                memory2 -= time;
            }
            ++time;
        }
        return {time, memory1, memory2};
    }
};
