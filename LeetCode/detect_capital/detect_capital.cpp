// Source: https://leetcode.com/problems/detect-capital/
// Description: Check if a word uses capitals correctly:
//   1) All letters are uppercase.
//   2) All letters are lowercase.
//   3) Only the first letter is uppercase (and the word has length > 1).

#include <string>
using namespace std;

class Solution {
    static bool isLower(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    static bool isUpper(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }

public:
    bool detectCapitalUse(const string& word) {
        int n = word.size();
        if (n == 0) return true;

        // Case 1: All lowercase?
        bool allLower = true;
        for (char c : word) {
            if (!isLower(c)) { allLower = false; break; }
        }
        if (allLower) return true;

        // Case 2: All uppercase?
        bool allUpper = true;
        for (char c : word) {
            if (!isUpper(c)) { allUpper = false; break; }
        }
        if (allUpper) return true;

        // Case 3: Only first uppercase, rest lowercase?
        if (isUpper(word[0])) {
            for (int i = 1; i < n; i++) {
                if (!isLower(word[i])) return false;
            }
            return true;
        }
        
        return false;
    }
};
