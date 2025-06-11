// source: https://leetcode.com/problems/remove-invalid-parentheses/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int removeLeft = 0, removeRight = 0;
        for (char c : s) {
            if (c == '(') {
                removeLeft++;
            } else if (c == ')') {
                if (removeLeft > 0) {
                    removeLeft--;
                } else {
                    removeRight++;
                }
            }
        }

        unordered_set<string> resultSet;
        dfs(s, 0, 0, 0, removeLeft, removeRight, "", resultSet);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    void dfs(const string& s, int index, int open, int close, int removeLeft,
             int removeRight, string path, unordered_set<string>& resultSet) {

        if (index == s.length()) {
            if (removeLeft == 0 && removeRight == 0 && open == close) {
                resultSet.insert(path);
            }
            return;
        }

        char c = s[index];

        if (c == '(') {
            // Option 1: remove it
            if (removeLeft > 0) {
                dfs(s, index + 1, open, close, removeLeft - 1, removeRight,
                    path, resultSet);
            }
            // Option 2: keep it
            dfs(s, index + 1, open + 1, close, removeLeft, removeRight,
                path + c, resultSet);

        } else if (c == ')') {
            // Option 1: remove it
            if (removeRight > 0) {
                dfs(s, index + 1, open, close, removeLeft, removeRight - 1,
                    path, resultSet);
            }
            // Option 2: keep it if valid
            if (close < open) {
                dfs(s, index + 1, open, close + 1, removeLeft, removeRight,
                    path + c, resultSet);
            }

        } else {
            // Keep non-parenthesis characters
            dfs(s, index + 1, open, close, removeLeft, removeRight, path + c,
                resultSet);
        }
    }
};
