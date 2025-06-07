// source: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        vector<int> leftCount(n), rightCount(n);
        unordered_set<char> leftSet, rightSet;

        for (int i = 0; i < n; ++i) {
            leftSet.insert(s[i]);
            leftCount[i] = leftSet.size();
        }

        for (int i = n - 1; i >= 0; --i) {
            rightSet.insert(s[i]);
            rightCount[i] = rightSet.size();
        }

        int goodSplits = 0;
        for (int i = 1; i < n; ++i) {
            if (leftCount[i - 1] == rightCount[i]) {
                ++goodSplits;
            }
        }

        return goodSplits;
    }
};
