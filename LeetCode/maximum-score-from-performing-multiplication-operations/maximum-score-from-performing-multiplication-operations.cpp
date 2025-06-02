// Source: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int m = multipliers.size();
        vector<vector<int>> memo(m + 1, vector<int>(m + 1, INT_MIN));
        return dp(0, 0, nums, multipliers, memo);
    }

private:
    int dp(int i, int left, const vector<int>& nums, const vector<int>& multipliers,
           vector<vector<int>>& memo) {
        if (i == multipliers.size()) return 0;
        if (memo[i][left] != INT_MIN) return memo[i][left];

        int right = nums.size() - 1 - (i - left);
        int pickLeft = nums[left] * multipliers[i] + dp(i + 1, left + 1, nums, multipliers, memo);
        int pickRight = nums[right] * multipliers[i] + dp(i + 1, left, nums, multipliers, memo);

        return memo[i][left] = max(pickLeft, pickRight);
    }
};
