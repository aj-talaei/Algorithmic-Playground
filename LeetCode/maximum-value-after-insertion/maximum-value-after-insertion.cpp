// Source: https://leetcode.com/problems/maximum-value-after-insertion/

class Solution {
public:
    string maxValue(string n, int x) {
        bool isNegative = n[0] == '-';
        int insertPos = isNegative ? 1 : 0;
        char ch = x + '0';

        while (insertPos < n.size()) {
            if ((isNegative && n[insertPos] - '0' > x) ||
                (!isNegative && n[insertPos] - '0' < x)) {
                break;
            }
            insertPos++;
        }

        n.insert(n.begin() + insertPos, ch);
        return n;
    }
};
