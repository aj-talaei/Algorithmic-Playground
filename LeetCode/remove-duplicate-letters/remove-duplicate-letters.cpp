// source: https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = {0};
        bool inStack[26] = {false};

        for (char c : s) {
            count[c - 'a']++;
        }

        string result;
        for (char c : s) {
            count[c - 'a']--;
            if (inStack[c - 'a'])
                continue;

            while (!result.empty() && result.back() > c &&
                   count[result.back() - 'a'] > 0) {
                inStack[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            inStack[c - 'a'] = true;
        }

        return result;
    }
};
