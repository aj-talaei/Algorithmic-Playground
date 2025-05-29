// Source : https://leetcode.com/problems/longest-consecutive-sequence/

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : nums) {
            if (!numSet.count(num)) continue; // already processed
            numSet.erase(num);

            int prev = num - 1;
            int next = num + 1;

            while (numSet.count(prev)) numSet.erase(prev--);
            while (numSet.count(next)) numSet.erase(next++);

            maxLen = std::max(maxLen, next - prev - 1);
        }

        return maxLen;
    }
};
