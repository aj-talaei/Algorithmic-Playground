// Source: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0, open = 0;
        int i = 0, n = s.size();

        while (i < n) {
            if (s[i] == '(') {
                ++open;
                ++i;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } else {
                    ++insertions; // need one more ')'
                    ++i;
                }

                if (open > 0) {
                    --open;
                } else {
                    ++insertions; // need one '(' before this '))'
                }
            }
        }

        return insertions + open * 2; // each unmatched '(' needs '))'
    }
};
