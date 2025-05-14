
// Given an integer array nums and an integer goal, return the minimum absolute difference 
// between the sum of any subsequence of nums and goal. A subsequence is any subset of the 
// original array elements in any order. The size of nums is at most 40, which suggests a 
// meet-in-the-middle approach is optimal.
//
// Constraints:
// - 1 <= nums.length <= 40
// - -1e7 <= nums[i] <= 1e7
// - -1e9 <= goal <= 1e9

class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        vector<long long> left, right;

        // Helper to generate all possible subset sums in a given range
        auto generateSums = [&](int l, int r, vector<long long>& res) {
            int n = r - l + 1;
            for (int i = 0; i < (1 << n); ++i) {
                long long sum = 0;
                for (int j = 0; j < n; ++j) {
                    if (i & (1 << j)) {
                        sum += nums[l + j];
                    }
                }
                res.push_back(sum);
            }
        };

        int n = nums.size();
        generateSums(0, n / 2 - 1, left);
        generateSums(n / 2, n - 1, right);

        sort(right.begin(), right.end());

        long long ans = LLONG_MAX;
        for (long long lsum : left) {
            long long target = goal - lsum;
            auto it = lower_bound(right.begin(), right.end(), target);

            if (it != right.end()) {
                ans = min(ans, abs(lsum + *it - goal));
            }
            if (it != right.begin()) {
                --it;
                ans = min(ans, abs(lsum + *it - goal));
            }
        }

        return (int)ans;
    }
};
