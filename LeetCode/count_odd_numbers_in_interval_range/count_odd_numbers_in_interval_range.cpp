
// Description:
//   Given two non-negative integers low and high, return the number of odd integers
//   in the inclusive interval [low, high]. Runs in O(1) time and O(1) space.

class Solution {
public:
    int countOdds(int low, int high) {
        // Number of odds ≤ high minus number of odds < low
        return (high + 1) / 2 - (low / 2);
    }
};
