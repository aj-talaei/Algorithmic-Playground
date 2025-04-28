"""
Problem Name: Two Number Sum
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of distinct integers and a target sum. If any two numbers
in the input array sum up to the target sum, the function should return them in an array, in any order.
If no two numbers sum up to the target sum, the function should return an empty array.

You cannot add a number to itself to reach the target sum.

Time Complexity: O(n)
Space Complexity: O(n)
"""

def twoNumberSum(array, targetSum):
    nums = {}
    for num in array:
        potentialMatch = targetSum - num
        if potentialMatch in nums:
            return [potentialMatch, num]
        else:
            nums[num] = True
    return []

# Example usage
if __name__ == "__main__":
    array = [3, 5, -4, 8, 11, 1, -1, 6]
    targetSum = 10
    result = twoNumberSum(array, targetSum)
    print("Two numbers that sum to target:", result)
