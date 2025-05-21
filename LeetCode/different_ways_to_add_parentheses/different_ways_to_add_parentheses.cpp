// Source: https://leetcode.com/problems/different-ways-to-add-parentheses/
// Description: Given a string of numbers and '+', '-', '*' operators, return all possible results
//              from computing all different ways to add parentheses (i.e., to change the order of operations).

#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>

class Solution {
    std::unordered_map<std::string, std::vector<int>> memo;

    static bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*';
    }

public:
    std::vector<int> diffWaysToCompute(const std::string& input) {
        if (auto it = memo.find(input); it != memo.end()) {
            return it->second;
        }
        std::vector<int> results;
        for (int i = 0; i < (int)input.size(); ++i) {
            char c = input[i];
            if (isOperator(c)) {
                // Divide
                auto left  = diffWaysToCompute(input.substr(0, i));
                auto right = diffWaysToCompute(input.substr(i + 1));
                // Conquer and merge
                for (int l : left) {
                    for (int r : right) {
                        int v = 0;
                        if      (c == '+') v = l + r;
                        else if (c == '-') v = l - r;
                        else                v = l * r;
                        results.push_back(v);
                    }
                }
            }
        }
        // If no operator was found, it's just a number
        if (results.empty()) {
            results.push_back(std::atoi(input.c_str()));
        }
        return memo[input] = results;
    }
};
