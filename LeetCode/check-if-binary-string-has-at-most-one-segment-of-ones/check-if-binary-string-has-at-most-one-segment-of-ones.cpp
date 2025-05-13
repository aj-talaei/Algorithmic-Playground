/*
 * Leetcode Problem: Check if Binary String Has at Most One Segment of Ones
 *
 * Given a binary string `s` that starts with '1' and contains only '0' or '1',
 * return true if it contains at most one contiguous segment of 1s. Otherwise, return false.
 *
 * Example:
 * Input: s = "1001" → Output: false
 * Input: s = "110"  → Output: true
 */
class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        while (i < s.size() && s[i] == '1') i++; // Skip first segment of 1s
        while (i < s.size() && s[i] == '0') i++; // Skip 0s after first segment
        return i == s.size(); // If there's another '1', i would not reach end
    }
};
