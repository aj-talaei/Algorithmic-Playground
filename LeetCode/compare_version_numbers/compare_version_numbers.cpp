
// Problem: Compare Version Numbers
// Link: https://leetcode.com/problems/compare-version-numbers/
//
// Description:
// Compare two version number strings `version1` and `version2`. Each version string
// consists of one or more non-negative integer levels separated by dots—for example,
// "1.0.2" or "13.37". Compare them level by level (ignoring leading zeros) and return:
//   - 1 if version1 > version2
//   - -1 if version1 < version2
//   - 0 otherwise
// Trailing “.0” levels are considered equal (e.g., "1.0.0" == "1").
//
// Constraints:
// - 1 <= version1.length, version2.length <= 500
// - version strings contain only digits and '.' characters.

#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(const string& version1, const string& version2) {
        int i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        while (i < n1 || j < n2) {
            long num1 = 0;
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }
            long num2 = 0;
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }
            if (num1 > num2) return 1;
            if (num1 < num2) return -1;
            // skip the dot separator
            if (i < n1 && version1[i] == '.') ++i;
            if (j < n2 && version2[j] == '.') ++j;
        }
        return 0;
    }
};
