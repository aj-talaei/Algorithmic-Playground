// Source: https://leetcode.com/problems/gas-station/
// Description: On a circular route of gas stations, `gas[i]` is the amount of gas at station i,
//              and it costs `cost[i]` gas to travel from station i to (i+1). Find the starting
//              station index from which you can complete the circuit once with an empty tank initially.
//              Return -1 if it’s impossible. It’s guaranteed that if a solution exists, it’s unique.

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        int n = gas.size();
        int start = 0;      // candidate start index
        int tank = 0;       // current gas in tank
        int total = 0;      // net total gas across all stations
        
        for (int i = 0; i < n; ++i) {
            int delta = gas[i] - cost[i];
            tank += delta;
            total += delta;
            // If tank goes negative, we cannot start from previous start -> reset
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        // If overall total gas is non-negative, start is valid; otherwise impossible
        return (total >= 0 && start < n) ? start : -1;
    }
};

