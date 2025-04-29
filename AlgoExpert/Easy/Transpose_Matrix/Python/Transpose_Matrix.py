"""
Problem Name: Transpose Matrix
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given a 2D array of integers (matrix), return the transpose of the matrix.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
"""

def transposeMatrix(matrix):
    transposedMatrix = []
    for col in range(len(matrix[0])):
        newRow = []
        for row in range(len(matrix)):
            newRow.append(matrix[row][col])
        transposedMatrix.append(newRow)
    return transposedMatrix

