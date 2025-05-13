/*
 * Leetcode Problem: Check if Array Is Sorted and Rotated
 *
 * Given an array `nums`, return true if it was originally sorted in non-decreasing order
 * and then rotated some number of positions (including zero). Otherwise, return false.
 *
 * A rotation means that the array `[a0, a1, ..., an-1]` becomes `[ai, ai+1, ..., an-1, a0, ..., ai-1]`
 * for some `i` in the range `[0, n)`.
 *
 * Example:
 * Input: nums = [3,4,5,1,2]
 * Output: true
 * Explanation: The original array [1,2,3,4,5] was rotated 3 times.
 */

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};
