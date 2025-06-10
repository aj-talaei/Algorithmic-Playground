// Source : https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Step 1: compute left products
        for (int i = 1; i < n; ++i) {
            output[i] = output[i - 1] * nums[i - 1];
        }

        // Step 2: compute right products and multiply
        int rightProduct = 1;
        for (int i = n - 2; i >= 0; --i) {
            rightProduct *= nums[i + 1];
            output[i] *= rightProduct;
        }

        return output;
    }
};
