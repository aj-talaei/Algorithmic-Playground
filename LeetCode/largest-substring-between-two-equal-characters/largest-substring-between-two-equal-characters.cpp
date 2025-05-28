// LeetCode: https://leetcode.com/problems/largest-substring-between-two-equal-characters/

// Problem:
// Find the longest substring (excluding the end characters) between two equal characters in a string.

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> firstPos(26, -1);
        int maxLength = -1;

        for (int i = 0; i < s.length(); ++i) {
            int idx = s[i] - 'a';
            if (firstPos[idx] == -1) {
                firstPos[idx] = i;
            } else {
                maxLength = max(maxLength, i - firstPos[idx] - 1);
            }
        }

        return maxLength;
    }
};
