// Source: https://leetcode.com/problems/first-missing-positive/
// Description: Given an unsorted integer array, find the smallest missing positive integer
// in O(n) time and O(1) extra space by placing each number n at index n−1 when possible.

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // Place each value x in its correct position at index x−1
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // The first place where index + 1 != value is the missing positive
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        // All 1..n are present
        return n + 1;
    }
};

