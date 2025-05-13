// Problem: Bulb Switcher
// Source: https://leetcode.com/problems/bulb-switcher/
//
// There are n bulbs initially turned off. You perform n rounds of toggling:
// - In the i-th round, you toggle every i-th bulb (on → off, off → on).
// Return the number of bulbs that are on after n rounds.
//
// A bulb ends up on only if it is toggled an odd number of times,
// which happens only for perfect squares (1, 4, 9, ...).
// So the result is the number of perfect squares <= n.

class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
