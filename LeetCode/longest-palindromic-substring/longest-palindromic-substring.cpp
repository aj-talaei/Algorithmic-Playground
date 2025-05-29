// Source : https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        for (int i = 0; i < s.size(); ++i) {
            expandAroundCenter(s, i, i, start, maxLen);     // Odd length
            expandAroundCenter(s, i, i + 1, start, maxLen); // Even length
        }

        return s.substr(start, maxLen);
    }

private:
    void expandAroundCenter(const string& s, int left, int right, int& start, int& maxLen) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        int len = right - left - 1;
        if (len > maxLen) {
            start = left + 1;
            maxLen = len;
        }
    }
};
