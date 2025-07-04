// Source: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

class Solution {
public:
    int minimumLength(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) ++left;
            while (left <= right && s[right] == ch) --right;
        }

        return right - left + 1;
    }
};
