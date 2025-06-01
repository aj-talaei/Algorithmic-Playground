// Source: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int maxSum = nums[0], minSum = nums[0];
        int currentMax = nums[0], currentMin = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            currentMax = std::max(nums[i], currentMax + nums[i]);
            maxSum = std::max(maxSum, currentMax);

            currentMin = std::min(nums[i], currentMin + nums[i]);
            minSum = std::min(minSum, currentMin);
        }

        return std::max(std::abs(maxSum), std::abs(minSum));
    }
};
