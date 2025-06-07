// source: https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        // Step 2: If such element is found, find the element just larger than it to the right
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the remaining suffix to get the next smallest lexicographic order
        reverse(nums.begin() + i + 1, nums.end());
    }
};
