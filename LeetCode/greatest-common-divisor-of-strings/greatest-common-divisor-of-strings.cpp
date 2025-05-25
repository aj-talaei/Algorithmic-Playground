// Source: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Description: Given two strings `str1` and `str2`, return the largest string `X` such that
//              `X` divides both (i.e., both `str1 == X+...+X` and `str2 == X+...+X`). If no
//              such string exists, return an empty string.

#include <string>
using namespace std;

class Solution {
public:
    string gcdOfStrings(const string& str1, const string& str2) {
        // If concatenations differ, no common divisor string exists
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        // Compute GCD of lengths and return the prefix of that length
        int len = gcd(str1.size(), str2.size());
        return str1.substr(0, len);
    }

private:
    // Euclidean algorithm for greatest common divisor
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};
