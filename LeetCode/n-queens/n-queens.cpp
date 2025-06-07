// source: https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<int> queens(n, -1);
        backtrack(0, n, queens, results);
        return results;
    }

private:
    void backtrack(int row, int n, vector<int>& queens, vector<vector<string>>& results) {
        if (row == n) {
            results.push_back(buildBoard(queens, n));
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, queens)) {
                queens[row] = col;
                backtrack(row + 1, n, queens, results);
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

    vector<string> buildBoard(const vector<int>& queens, int n) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};
