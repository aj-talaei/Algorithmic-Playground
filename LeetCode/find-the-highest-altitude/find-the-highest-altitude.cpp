// Source: https://leetcode.com/problems/find-the-highest-altitude/
// Description: Given an integer array `gain` where `gain[i]` is the net gain in altitude
//              between points i and i+1 (starting at altitude 0), return the highest altitude reached.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_altitude = 0;
        int curr_altitude = 0;
        for (int delta : gain) {
            curr_altitude += delta;
            max_altitude = max(max_altitude, curr_altitude);
        }
        return max_altitude;
    }
};

