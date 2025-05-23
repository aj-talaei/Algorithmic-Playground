
// Source: https://leetcode.com/problems/find-the-difference/
// Description: Given two strings s and t where t is s shuffled with one extra character added, find that extra character.

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        unordered_map<char, int> count;
        for (char c : s) {
            ++count[c];
        }
        for (char c : t) {
            if (--count[c] < 0) {
                return c;
            }
        }
        return '\0';  // Should never happen if input is valid
    }
};
