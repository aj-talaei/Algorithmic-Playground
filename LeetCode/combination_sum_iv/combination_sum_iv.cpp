// Problem: Combination Sum IV
// Link: https://leetcode.com/problems/combination-sum-iv/
//
// Description:
// Given an array of distinct positive integers `nums` and a positive integer `target`,
// return the number of possible ordered combinations that add up to `target`. 
// Different sequences count as distinct combinations.
//
// Example:
// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation: The combinations are:
//   (1,1,1,1), (1,1,2), (1,2,1), (2,1,1), (2,2), (1,3), (3,1)
//
// Constraints:
// - 1 <= nums.length <= 200
// - 1 <= nums[i] <= 1000
// - All elements of nums are distinct.
// - 0 <= target <= 1000
// - The answer is guaranteed to fit in a signed 32-bit integer.

#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] = number of ways to form sum i
        // Use 64-bit to prevent intermediate overflow
        vector<unsigned long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int sum = 1; sum <= target; ++sum) {
            for (int num : nums) {
                if (sum >= num) {
                    dp[sum] += dp[sum - num];
                }
            }
        }
        return static_cast<int>(dp[target]);
    }
};
