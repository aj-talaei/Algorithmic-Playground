// Problem: Binary Watch
// Source: https://leetcode.com/problems/binary-watch/
//
// A binary watch has 4 LEDs for hours (0-11) and 6 LEDs for minutes (0-59).
// Given an integer `num`, return all possible times the watch could represent
// with exactly `num` LEDs turned on.
//
// Example:
// Input: num = 1
// Output: ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == num) {
                    char buf[6];
                    sprintf(buf, "%d:%02d", h, m);
                    result.push_back(buf);
                }
            }
        }
        return result;
    }
};
