// Problem: https://leetcode.com/problems/increasing-triplet-subsequence/
// Given an unsorted array, determine whether an increasing subsequence of length 3 exists.
// Formally, return true if there exist indices i < j < k such that nums[i] < nums[j] < nums[k].
// The solution must run in O(n) time and O(1) space.

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int num : nums) {
            if (num <= first) {
                first = num;            // Smallest so far
            } else if (num <= second) {
                second = num;           // Second smallest
            } else {
                return true;            // Found third number greater than both
            }
        }

        return false;
    }
};
