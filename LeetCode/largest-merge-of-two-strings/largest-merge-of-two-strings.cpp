// LeetCode: https://leetcode.com/problems/largest-merge-of-two-strings/

// Problem:
// Construct the lexicographically largest merge by greedily choosing the first character from either
// `word1` or `word2` at each step.

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i = 0, j = 0;
        int n = word1.size(), m = word2.size();
        string result;

        while (i < n && j < m) {
            if (word1.substr(i) > word2.substr(j)) {
                result += word1[i++];
            } else {
                result += word2[j++];
            }
        }

        result += word1.substr(i);
        result += word2.substr(j);

        return result;
    }
};
