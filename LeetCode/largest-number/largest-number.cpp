// LeetCode: https://leetcode.com/problems/largest-number/

// Problem:
// Given an array of non-negative integers, arrange them such that they form the largest number.
// Return the result as a string to handle large values.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // Handle the case where the largest number is "0"
        if (strNums[0] == "0") return "0";

        string result;
        for (const string& s : strNums) {
            result += s;
        }

        return result;
    }
};
