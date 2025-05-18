// Problem: Contains Duplicate II
// Link: https://leetcode.com/problems/contains-duplicate-ii/
//
// Description:
// Given an array of integers `nums` and an integer `k`, determine whether there are
// two distinct indices `i` and `j` in the array such that `nums[i] == nums[j]` and
// `|i - j| <= k`.
//
// Constraints:
//  - 1 ≤ nums.length ≤ 10^5
//  - -10^9 ≤ nums[i] ≤ 10^9
//  - 0 ≤ k ≤ 10^5
//
// Approach:
// Use a sliding‐window `unordered_set` of size at most `k`. As we iterate through `nums`,
// we keep the last `k` values in the set. For each new element:
//   1. If it's already in the set, we found a duplicate within distance ≤ k → return true.
//   2. Otherwise, insert it.
//   3. If the set size exceeds k, remove the element that fell out of the window (`nums[i-k]`).
// This runs in O(n) average time and O(min(n, k)) space.

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_set<int> window;
        window.reserve(min((size_t)k + 1, nums.size()));
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (window.count(nums[i])) {
                return true;
            }
            window.insert(nums[i]);
            if ((int)window.size() > k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};
