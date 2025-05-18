// Problem: Contains Duplicate
// Link: https://leetcode.com/problems/contains-duplicate/
//
// Description:
// Given an array of integers `nums`, determine if any value appears at least twice in the array.
// Return `true` if the array contains any duplicates, and `false` otherwise.
//
// Constraints:
//  - 1 ≤ nums.length ≤ 10^5
//  - -10^9 ≤ nums[i] ≤ 10^9

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(const vector<int>& nums) {
        unordered_set<int> seen;
        seen.reserve(nums.size());
        for (int x : nums) {
            // try to insert; if already present, it's a duplicate
            if (!seen.insert(x).second) 
                return true;
        }
        return false;
    }
};
