// Source: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorAll = 0;
        for (int num : nums) xorAll ^= num;

        int maxVal = (1 << maximumBit) - 1;
        vector<int> result;
        result.reserve(nums.size());

        for (int i = nums.size() - 1; i >= 0; --i) {
            result.push_back(xorAll ^ maxVal);
            xorAll ^= nums[i];
        }

        return result;
    }
};
