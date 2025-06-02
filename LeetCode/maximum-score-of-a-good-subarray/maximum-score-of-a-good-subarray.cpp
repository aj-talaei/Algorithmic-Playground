// Source: https://leetcode.com/problems/maximum-score-of-a-good-subarray/

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int left = k, right = k;
        int minVal = nums[k];
        int maxScore = minVal;

        while (left > 0 || right < n - 1) {
            if (left == 0) {
                right++;
            } else if (right == n - 1) {
                left--;
            } else if (nums[left - 1] > nums[right + 1]) {
                left--;
            } else {
                right++;
            }

            minVal = min(minVal, min(nums[left], nums[right]));
            maxScore = max(maxScore, minVal * (right - left + 1));
        }

        return maxScore;
    }
};
