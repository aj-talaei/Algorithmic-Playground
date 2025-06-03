// Problem: Minimize Maximum Pair Sum in Array
// Source  : https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int maxPairSum = 0;
        for (int i = 0, j = nums.size() - 1; i < j; ++i, --j) {
            maxPairSum = std::max(maxPairSum, nums[i] + nums[j]);
        }
        return maxPairSum;
    }
};
