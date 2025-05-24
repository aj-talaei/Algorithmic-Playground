// Source: https://leetcode.com/problems/first-unique-character-in-a-string/
// Description: Given a lowercase string `s`, return the index of the first non-repeating character.
//              If none exists, return -1.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int firstUniqChar(const string& s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        for (int i = 0; i < (int)s.size(); ++i) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};
