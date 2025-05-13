/*
 * Leetcode Problem: Check if One String Swap Can Make Strings Equal
 *
 * Given two strings s1 and s2 of equal length, return true if you can make them equal 
 * by swapping exactly one pair of characters in one of the strings. Otherwise, return false.
 *
 * Example:
 * Input: s1 = "bank", s2 = "kanb" → Output: true
 * Input: s1 = "attack", s2 = "defend" → Output: false
 * Input: s1 = "kelb", s2 = "kelb" → Output: true
 */

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> diff;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) diff.push_back(i);
        }

        return diff.size() == 0 ||
               (diff.size() == 2 && s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
    }
};
