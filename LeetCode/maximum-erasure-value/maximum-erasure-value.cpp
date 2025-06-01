// Source: https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        const int NIL = -1;
        int pos[10001];
        std::fill(std::begin(pos), std::end(pos), NIL);

        int left = 0, sum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int val = nums[right];
            if (pos[val] != NIL && pos[val] >= left) {
                while (left <= pos[val]) {
                    sum -= nums[left];
                    pos[nums[left++]] = NIL;
                }
            }
            sum += val;
            pos[val] = right;
            maxSum = std::max(maxSum, sum);
        }

        return maxSum;
    }
};
