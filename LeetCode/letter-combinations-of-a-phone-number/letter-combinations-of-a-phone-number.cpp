// LeetCode: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Problem:
// Return all possible letter combinations for a digit string using telephone keypad mappings.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        const vector<string> phone = {
            "",     "",     "abc",  "def", "ghi",
            "jkl",  "mno",  "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        backtrack(digits, 0, "", phone, result);
        return result;
    }

private:
    void backtrack(const string& digits, int index, string current,
                   const vector<string>& phone, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : phone[digit]) {
            backtrack(digits, index + 1, current + c, phone, result);
        }
    }
};
