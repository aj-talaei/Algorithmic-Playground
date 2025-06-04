// Source: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            int ops = 0;

            for (int balls : nums) {
                ops += (balls - 1) / mid;
            }

            if (ops > maxOperations) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
