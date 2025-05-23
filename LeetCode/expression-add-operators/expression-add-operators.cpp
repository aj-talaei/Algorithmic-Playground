// Source: https://leetcode.com/problems/expression-add-operators/
// Description: Given a string of digits and a target value, insert the binary operators +, - or *
// between the digits so that the resulting expression evaluates to the target. Return all valid
// expressions in any order.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> addOperators(const string& num, int target) {
        vector<string> result;
        if (num.empty()) return result;
        dfs(num, target, 0, 0, 0, "", result);
        return result;
    }

private:
    // pos      - current index in num
    // eval     - current evaluated value of the expression so far
    // multed   - the value of the last operand in the expression (to handle multiplication precedence)
    // path     - the expression built so far
    // result   - collects all valid expressions
    void dfs(const string& num, int target, int pos,
             long long eval, long long multed,
             const string& path, vector<string>& result) {
        
        if (pos == num.size()) {
            if (eval == target) result.push_back(path);
            return;
        }
        
        // Try all possible splits of the remaining digits
        for (int i = pos; i < num.size(); ++i) {
            // Skip numbers with leading zero
            if (i > pos && num[pos] == '0') break;
            
            long long cur = stoll(num.substr(pos, i - pos + 1));
            string curStr = num.substr(pos, i - pos + 1);
            
            if (pos == 0) {
                // First number in the expression: no operator preceding it
                dfs(num, target, i + 1, cur, cur, curStr, result);
            } else {
                // Addition
                dfs(num, target, i + 1, eval + cur,  cur,           path + "+" + curStr, result);
                // Subtraction
                dfs(num, target, i + 1, eval - cur, -cur,           path + "-" + curStr, result);
                // Multiplication: undo the last operand and apply multiplication
                dfs(num, target, i + 1,
                    eval - multed + multed * cur,
                    multed * cur,
                    path + "*" + curStr,
                    result);
            }
        }
    }
};
