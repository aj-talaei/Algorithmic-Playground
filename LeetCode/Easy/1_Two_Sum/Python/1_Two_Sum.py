"""
Problem Name: Two Sum
Problem Number: 1
Difficulty: Easy
Platform: LeetCode

Problem Description:
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to the target.
Each input would have exactly one solution, and you may not use the same element twice.

Approach:
- Use a hash map (dictionary) to store number and index.
- For each number, calculate its complement (target - num).
- If the complement exists in the map, return their indices.
- Otherwise, add the number and its index to the map.

Time Complexity: O(n)
Space Complexity: O(n)

Problem Link: https://leetcode.com/problems/two-sum/
"""

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_index = {}
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_index:
                return [num_index[complement], i]
            num_index[num] = i
        return []

# Example usage
if __name__ == "__main__":
    solution = Solution()
    nums = [2, 7, 11, 15]
    target = 9
    result = solution.twoSum(nums, target)
    print("Indices:", result)