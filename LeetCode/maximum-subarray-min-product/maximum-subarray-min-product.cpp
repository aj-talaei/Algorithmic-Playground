// Source: https://leetcode.com/problems/maximum-subarray-min-product/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        nums.push_back(0); // Sentinel to flush stack at the end

        // Prefix sums: sums[i] = sum(nums[0..i-1])
        vector<long long> prefix(n + 2, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        stack<int> s;
        long long maxProduct = 0;

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                int idx = s.top(); s.pop();
                int left = s.empty() ? 0 : s.top() + 1;
                long long subarraySum = prefix[i] - prefix[left];
                maxProduct = max(maxProduct, subarraySum * nums[idx]);
            }
            s.push(i);
        }

        return maxProduct % MOD;
    }
};
