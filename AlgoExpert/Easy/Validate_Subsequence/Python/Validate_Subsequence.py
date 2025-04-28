"""
Problem Name: Validate Subsequence
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given two non-empty arrays of integers, determine whether the second array is a subsequence of the first one.

A subsequence of an array is a set of numbers that are in the same order as they appear in the array,
but not necessarily contiguous.

Time Complexity: O(n)
Space Complexity: O(1)
"""

def isValidSubsequence(array, sequence):
    arrayIdx = 0
    seqIdx = 0
    while arrayIdx < len(array) and seqIdx < len(sequence):
        if array[arrayIdx] == sequence[seqIdx]:
            seqIdx += 1
        arrayIdx += 1
    return seqIdx == len(sequence)

# Example usage
if __name__ == "__main__":
    array = [5, 1, 22, 25, 6, -1, 8, 10]
    sequence = [1, 6, -1, 10]
    result = isValidSubsequence(array, sequence)
    print("Is valid subsequence:", result)
