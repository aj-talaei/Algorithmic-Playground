// Source: https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/
// Description: Given a list of integer groups and an array nums, determine if you can select
//              disjoint subarrays from nums, in the same order as groups, such that each
//              subarray equals the corresponding group.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canChoose(const vector<vector<int>>& groups, const vector<int>& nums) {
        int pos = 0;
        for (const auto& g : groups) {
            // find subarray g in nums starting at or after pos
            auto it = search(nums.begin() + pos, nums.end(), g.begin(), g.end());
            if (it == nums.end()) {
                return false;
            }
            // advance past this matched subarray
            pos = (int)(it - nums.begin()) + (int)g.size();
        }
        return true;
    }
};

