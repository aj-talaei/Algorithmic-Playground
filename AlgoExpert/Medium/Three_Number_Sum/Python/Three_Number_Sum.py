"""
Problem Name: Three Number Sum
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of distinct integers and a target sum.
The function should find all triplets in the array that sum up to the target sum and return
a two-dimensional array of all these triplets. The numbers in each triplet should be ordered
in ascending order, and the triplets themselves should be ordered in ascending order with respect
to the numbers they hold.

If no three numbers sum up to the target sum, the function should return an empty array.

Time Complexity: O(n^2)
Space Complexity: O(n)
"""

def threeNumberSum(array, targetSum):
    array.sort()
    triplets = []
    for i in range(len(array) - 2):
        left = i + 1
        right = len(array) - 1
        while left < right:
            currentSum = array[i] + array[left] + array[right]
            if currentSum == targetSum:
                triplets.append([array[i], array[left], array[right]])
                left += 1
                right -= 1
            elif currentSum < targetSum:
                left += 1
            else:
                right -= 1
    return triplets

# Example usage
if __name__ == "__main__":
    array = [12, 3, 1, 2, -6, 5, -8, 6]
    targetSum = 0
    result = threeNumberSum(array, targetSum)
    print("Triplets summing to target:", result)
