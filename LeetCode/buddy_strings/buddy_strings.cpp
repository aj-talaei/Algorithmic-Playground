// Problem: Buddy Strings
// Source: https://leetcode.com/problems/buddy-strings/
//
// Given two strings A and B, return true if and only if we can swap two letters in A
// so that the result equals B. A and B consist only of lowercase letters.

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A.size() < 2) return false;

        bool hasDuplicate = false;
        bool seen[26] = {false};
        int diff[2], diffCount = 0;

        for (int i = 0; i < A.size(); i++) {
            if (seen[A[i] - 'a']) hasDuplicate = true;
            seen[A[i] - 'a'] = true;

            if (A[i] != B[i]) {
                if (diffCount >= 2) return false;
                diff[diffCount++] = i;
            }
        }

        if (diffCount == 0) return hasDuplicate;
        if (diffCount != 2) return false;

        return A[diff[0]] == B[diff[1]] && A[diff[1]] == B[diff[0]];
    }
};
