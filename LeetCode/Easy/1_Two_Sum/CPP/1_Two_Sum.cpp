/*
Problem Name: Two Sum
Problem Number: 1
Difficulty: Easy
Platform: LeetCode

Problem Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to the
target. You may assume that each input would have exactly one solution, and you may not use the same element twice.

Approach:
- Use an unordered map to store number values and their corresponding indices.
- For each number, compute its complement (target - current number).
- If the complement exists in the map, return the indices.
- Otherwise, insert the current number with its index into the map.

Time Complexity: O(n)
Space Complexity: O(n)

Problem Link: https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numIndex.count(complement)) {
                return {numIndex[complement], i};
            }
            numIndex[nums[i]] = i;
        }
        return {};  // No solution found (based on constraints, shouldn't happen)
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}