// Source: https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxProd = nums[0];
        int maxSoFar = nums[0], minSoFar = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            if (curr < 0) {
                swap(maxSoFar, minSoFar);
            }

            maxSoFar = max(curr, maxSoFar * curr);
            minSoFar = min(curr, minSoFar * curr);
            maxProd = max(maxProd, maxSoFar);
        }

        return maxProd;
    }
};
