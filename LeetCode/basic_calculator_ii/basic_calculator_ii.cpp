// Problem: Basic Calculator II
// Link: https://leetcode.com/problems/basic-calculator-ii/
// Difficulty: Medium
// Author: Amir Javid Talaei
//
// Given a string s which represents an expression, evaluate this expression and return its value.
//
// The expression contains only non-negative integers, '+', '-', '*', and '/' operators, and empty spaces.
// The integer division should truncate toward zero.
//
// Example:
// Input: s = "3+2*2"
// Output: 7
//
// Constraints:
// - 1 <= s.length <= 3 * 10^5
// - s consists of integers and operators ('+', '-', '*', '/') separated by spaces
// - s represents a valid expression
// - All the integers in the expression are non-negative integers in the range [0, 2^31 - 1]
// - The answer is guaranteed to fit in a 32-bit integer

#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int current = 0;
        char operation = '+';
        stack<int> stk;

        for (size_t i = 0; i <= s.length(); ++i) {
            char c = (i < s.length()) ? s[i] : '+';

            if (isdigit(c)) {
                current = current * 10 + (c - '0');
            }

            if ((!isdigit(c) && !isspace(c)) || i == s.length()) {
                if (operation == '+') {
                    stk.push(current);
                } else if (operation == '-') {
                    stk.push(-current);
                } else if (operation == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * current);
                } else if (operation == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / current);
                }
                operation = c;
                current = 0;
            }
        }

        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};
