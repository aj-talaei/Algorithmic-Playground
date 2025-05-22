// Source: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Description: Evaluate the value of an arithmetic expression in Reverse Polish Notation.

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(const vector<string>& tokens) {
        stack<int> st;
        for (const auto& tok : tokens) {
            if (tok.size() > 1 || isdigit(tok[0])) {
                // it's a (possibly negative) number
                st.push(stoi(tok));
            } else {
                // it's an operator
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                switch (tok[0]) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                }
            }
        }
        return st.top();
    }
};
