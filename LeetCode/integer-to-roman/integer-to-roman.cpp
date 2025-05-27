// Problem: Integer to Roman
// URL: https://leetcode.com/problems/integer-to-roman/
// Convert an integer in the range [1, 3999] into its Roman numeral representation.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // value–symbol pairs in descending order
        vector<pair<int, string>> romans = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100,  "C"}, {90,  "XC"}, {50,  "L"}, {40,  "XL"},
            {10,   "X"}, {9,   "IX"}, {5,   "V"}, {4,   "IV"},
            {1,    "I"}
        };
        
        string result;
        for (auto& [value, sym] : romans) {
            while (num >= value) {
                result += sym;
                num -= value;
            }
        }
        return result;
    }
};
