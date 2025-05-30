// Source : https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        const int MAXX = 1 << 10; // 1024
        int n = nums.size();

        vector<unordered_map<int, int>> freq(k);
        vector<int> count(k, 0);

        for (int i = 0; i < n; ++i) {
            freq[i % k][nums[i]]++;
            count[i % k]++;
        }

        vector<int> dp(MAXX, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < k; ++i) {
            int total = count[i];
            int minPrev = *min_element(dp.begin(), dp.end());
            vector<int> new_dp(MAXX, minPrev + total);

            for (auto& [v, f] : freq[i]) {
                for (int x = 0; x < MAXX; ++x) {
                    if (dp[x ^ v] != INT_MAX) {
                        new_dp[x] = min(new_dp[x], dp[x ^ v] + total - f);
                    }
                }
            }

            dp = move(new_dp);
        }

        return dp[0];
    }
};
