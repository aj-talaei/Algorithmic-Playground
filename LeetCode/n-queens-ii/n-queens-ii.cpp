// source: https://leetcode.com/problems/n-queens-ii/

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> queens(n, -1);
        backtrack(0, n, queens, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<int>& queens, int& count) {
        if (row == n) {
            ++count;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, queens)) {
                queens[row] = col;
                backtrack(row + 1, n, queens, count);
                queens[row] = -1;
            }
        }
    }

    bool isValid(int row, int col, const vector<int>& queens) {
        for (int i = 0; i < row; ++i) {
            int qCol = queens[i];
            if (qCol == col || abs(qCol - col) == row - i) {
                return false;
            }
        }
        return true;
    }
};
