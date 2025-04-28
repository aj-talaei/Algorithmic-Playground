"""
Problem Name: Sorted Squared Array
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Write a function that takes in a non-empty array of integers that are sorted in ascending order
and returns a new array of the same length with the squares of the original integers also sorted in ascending order.

Time Complexity: O(n)
Space Complexity: O(n)
"""

def sortedSquaredArray(array):
    sortedSquares = [0 for _ in array]
    leftIdx = 0
    rightIdx = len(array) - 1

    for i in reversed(range(len(array))):
        leftValue = array[leftIdx]
        rightValue = array[rightIdx]
        if abs(leftValue) > abs(rightValue):
            sortedSquares[i] = leftValue * leftValue
            leftIdx += 1
        else:
            sortedSquares[i] = rightValue * rightValue
            rightIdx -= 1

    return sortedSquares

# Example usage
if __name__ == "__main__":
    array = [1, 2, 3, 5, 6, 8, 9]
    result = sortedSquaredArray(array)
    print("Sorted squared array:", result)
