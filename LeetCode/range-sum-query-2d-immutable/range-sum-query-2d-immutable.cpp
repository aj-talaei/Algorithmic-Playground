// Source : https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
private:
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;

        // Initialize prefix sum matrix with an extra row and column (padding with 0s)
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1]
                             - prefix[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1]
             - prefix[row1][col2 + 1]
             - prefix[row2 + 1][col1]
             + prefix[row1][col1];
    }
};
