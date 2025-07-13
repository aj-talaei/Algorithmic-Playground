// Source : https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // Remove remaining digits from the end if needed
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Remove leading zeros
        int nonZeroIdx = 0;
        while (nonZeroIdx < stack.size() && stack[nonZeroIdx] == '0') {
            nonZeroIdx++;
        }

        string result = stack.substr(nonZeroIdx);
        return result.empty() ? "0" : result;
    }
};