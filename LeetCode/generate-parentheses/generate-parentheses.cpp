// Source: https://leetcode.com/problems/generate-parentheses/
// Description: Given `n` pairs of parentheses, generate all combinations of well-formed parentheses.

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        current.reserve(2 * n);
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(vector<string>& res, string& cur, int open, int close, int maxPairs) {
        if (cur.size() == 2 * maxPairs) {
            res.push_back(cur);
            return;
        }
        if (open < maxPairs) {
            cur.push_back('(');
            backtrack(res, cur, open + 1, close, maxPairs);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(res, cur, open, close + 1, maxPairs);
            cur.pop_back();
        }
    }
};

