/*
Problem Name: Transpose Matrix
Difficulty: Easy
Platform: AlgoExpert

Problem Description:
Given a 2D array of integers (matrix), return the transpose of the matrix.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/


#include <vector>
using namespace std;


vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposedMatrix(cols, vector<int>(rows));

    for (int col = 0; col < cols; ++col) {
        for (int row = 0; row < rows; ++row) {
            transposedMatrix[col][row] = matrix[row][col];
        }
    }
    return transposedMatrix;
}

