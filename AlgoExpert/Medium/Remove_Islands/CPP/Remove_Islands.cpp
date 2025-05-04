
/*
Problem Name: Remove Islands
Difficulty: Medium
Platform: AlgoExpert

Problem Statement:
You're given a two-dimensional array (a matrix) of potentially unequal height and width
containing only 0s and 1s. The matrix represents a two-toned image, where each 1 represents
black and each 0 represents white.

An island is defined as any number of 1s that are horizontally or vertically adjacent
(but not diagonally adjacent) and that don't touch the border of the image. In other words,
a group of horizontally or vertically adjacent 1s isn't an island if any of those 1s are in
the first row, last row, first column, or last column of the input matrix.

Write a function that returns a modified version of the input matrix, where all of the islands
are removed. You remove an island by replacing all of its 1s with 0s.

You're allowed to mutate the input matrix.

Time Complexity: O(n * m)
Space Complexity: O(n * m)
*/

#include <vector>
using namespace std;

vector<vector<int>> getNeighbors(vector<vector<int>>& matrix, int row, int col) {
    vector<vector<int>> neighbors;
    int numRows = matrix.size();
    int numCols = matrix[row].size();

    if (row - 1 >= 0) {
        neighbors.push_back({row - 1, col});  // UP
    }
    if (row + 1 < numRows) {
        neighbors.push_back({row + 1, col});  // DOWN
    }
    if (col - 1 >= 0) {
        neighbors.push_back({row, col - 1});  // LEFT
    }
    if (col + 1 < numCols) {
        neighbors.push_back({row, col + 1});  // RIGHT
    }

    return neighbors;
}

void findOnesConnectedToBorder(vector<vector<int>>& matrix, int startRow, int startCol,
                               vector<vector<bool>>& onesConnectedToBorder) {
    vector<vector<int>> stack = {{startRow, startCol}};

    while (stack.size() > 0) {
        auto currentPosition = stack[stack.size() - 1];
        stack.pop_back();
        int currentRow = currentPosition[0];
        int currentCol = currentPosition[1];

        bool alreadyVisited = onesConnectedToBorder[currentRow][currentCol];
        if (alreadyVisited) {
            continue;
        }

        onesConnectedToBorder[currentRow][currentCol] = true;

        auto neighbors = getNeighbors(matrix, currentRow, currentCol);
        for (auto neighbor : neighbors) {
            int row = neighbor[0];
            int col = neighbor[1];

            if (matrix[row][col] != 1) {
                continue;
            }
            stack.push_back(neighbor);
        }
    }
}

vector<vector<int>> removeIslands(vector<vector<int>> matrix) {

    vector<vector<bool>> onesConnectedToBorder(matrix.size(), vector<bool>(matrix[0].size(), false));

    // Find all the 1s that are not connected to the 1's in the border
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            bool rowIsBorder = row == 0 || row == matrix.size() - 1;
            bool colIsBorder = col == 0 || col == matrix[row].size() - 1;
            bool isBorder = rowIsBorder || colIsBorder;

            if (!isBorder) {
                continue;
            }

            if (matrix[row][col] != 1) {
                continue;
            }

            findOnesConnectedToBorder(matrix, row, col, onesConnectedToBorder);
        }
    }

    for (int row = 1; row < matrix.size() - 1; row++) {
        for (int col = 1; col < matrix[row].size() - 1; col++) {
            if (onesConnectedToBorder[row][col]) {
                continue;
            }
            matrix[row][col] = 0;
        }
    }

    return matrix;
}
