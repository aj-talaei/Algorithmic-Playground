// source: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || t.size() > s.size()) return "";

        unordered_map<char, int> targetFreq;
        for (char c : t) targetFreq[c]++;

        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        int required = targetFreq.size(), formed = 0;
        unordered_map<char, int> windowFreq;

        while (right < s.size()) {
            char c = s[right++];
            windowFreq[c]++;
            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            while (formed == required) {
                if (right - left < minLen) {
                    minLen = right - left;
                    start = left;
                }

                char leftChar = s[left++];
                if (targetFreq.count(leftChar) && windowFreq[leftChar] == targetFreq[leftChar]) {
                    formed--;
                }
                windowFreq[leftChar]--;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
