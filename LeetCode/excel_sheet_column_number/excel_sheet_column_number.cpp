// Source: https://leetcode.com/problems/excel-sheet-column-number/
// Description: Given an Excel column title, return its corresponding column number.

#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(const string& columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            result = result * 26 + (c - 'A' + 1);
        }
        return result;
    }
};
