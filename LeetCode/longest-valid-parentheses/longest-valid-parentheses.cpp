// Source : https://leetcode.com/problems/longest-valid-parentheses/

#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        std::stack<int> stk;
        int maxLen = 0, lastInvalid = -1;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (!stk.empty()) {
                    stk.pop();
                    int len = stk.empty() ? i - lastInvalid : i - stk.top();
                    maxLen = std::max(maxLen, len);
                } else {
                    lastInvalid = i;
                }
            }
        }

        return maxLen;
    }
};
