// Problem: Burst Balloons
// Source: https://leetcode.com/problems/burst-balloons/
//
// You are given an array `nums` where each element represents a balloon with a number on it.
// When you burst balloon `i`, you gain `nums[left] * nums[i] * nums[right]` coins,
// where `left` and `right` are adjacent (not yet burst) indices of `i`.
// Return the maximum number of coins you can collect by bursting the balloons wisely.
//
// Note:
// - Add virtual balloons with value 1 at both ends: nums[-1] = nums[n] = 1.
// - You cannot burst nums[-1] or nums[n].

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // Remove zero-value balloons since they contribute nothing
        nums.erase(remove_if(nums.begin(), nums.end(), [](int n){ return n == 0; }), nums.end());

        // Add virtual balloons at both ends with value 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        return maxCoinsDP(nums, dp);
    }

private:
    // Dynamic Programming approach
    int maxCoinsDP(vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        // gap (k) is the length between low and high
        for (int k = 2; k < n; ++k) {
            for (int low = 0; low < n - k; ++low) {
                int high = low + k;
                for (int i = low + 1; i < high; ++i) {
                    dp[low][high] = max(dp[low][high],
                        nums[low] * nums[i] * nums[high] + dp[low][i] + dp[i][high]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
