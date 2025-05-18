// Problem: Contains Duplicate III
// Link: https://leetcode.com/problems/contains-duplicate-iii/
//
// Description:
// Given an integer array `nums` and two integers `k` and `t`, determine whether there exist
// two distinct indices `i` and `j` in the array such that:
//   1) |nums[i] - nums[j]| ≤ t, and
//   2) |i - j| ≤ k.
//
// Constraints:
//  - 0 ≤ nums.length ≤ 10^5
//  - -2^31 ≤ nums[i] ≤ 2^31 - 1
//  - 0 ≤ k ≤ 10^5
//  - 0 ≤ t ≤ 2^31 - 1
//
// Approach:
// Maintain a sliding window of at most `k` previous elements using a balanced BST (`std::set`).
// For each new element `x = nums[i]`:
//   1. Evict `nums[i - k - 1]` from the set if the window size exceeds `k`.
//   2. Use `set.lower_bound(x - t)` to find the smallest element ≥ `x - t`.
//   3. Check if this element is within `x + t`. If so, return true.
//   4. Insert `x` into the set and continue.
// This runs in O(n log k) time and O(min(n, k)) space.

#include <vector>
#include <set>
#include <cstdint>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(const vector<int>& nums, int k, int t) {
        if (k <= 0 || t < 0 || nums.size() < 2) return false;
        set<int64_t> window;
        int left = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            // Keep window size ≤ k
            if (i - left > k) {
                window.erase((int64_t)nums[left]);
                ++left;
            }
            int64_t x = nums[i];
            // Find first element ≥ x - t
            auto it = window.lower_bound(x - t);
            // Check if |x - *it| ≤ t
            if (it != window.end() && *it - x <= t) {
                return true;
            }
            window.insert(x);
        }
        return false;
    }
};
