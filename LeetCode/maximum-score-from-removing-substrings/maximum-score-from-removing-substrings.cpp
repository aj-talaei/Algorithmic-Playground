// Source: https://leetcode.com/problems/maximum-score-from-removing-substrings/

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Always process the higher-value pair first
        char first = 'a', second = 'b';
        if (y > x) {
            swap(x, y);
            swap(first, second); // prioritize "ba" over "ab"
        }

        int score = 0;
        string leftover;

        // Step 1: Remove high-value substrings greedily (first+second)
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == first && c == second) {
                st.pop();
                score += x;
            } else {
                st.push(c);
            }
        }

        // Build leftover string to process remaining lower-value pattern
        while (!st.empty()) {
            leftover += st.top();
            st.pop();
        }
        reverse(leftover.begin(), leftover.end());

        // Step 2: Remove low-value substrings (second+first)
        for (char c : leftover) {
            if (!st.empty() && st.top() == second && c == first) {
                st.pop();
                score += y;
            } else {
                st.push(c);
            }
        }

        return score;
    }
};
