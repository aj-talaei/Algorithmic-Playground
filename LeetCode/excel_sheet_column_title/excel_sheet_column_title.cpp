// Source: https://leetcode.com/problems/excel-sheet-column-title/
// Description: Given a positive integer, return its corresponding Excel column title.

#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n > 0) {
            --n;  // adjust to 0-based
            result.insert(result.begin(), char('A' + (n % 26)));
            n /= 26;
        }
        return result;
    }
};
