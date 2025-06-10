// source: https://leetcode.com/problems/permutation-sequence/description

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int factorial = 1;

        // Prepare numbers 1 to n and compute n!
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
            factorial *= i;
        }

        if (k > factorial) return "";

        --k; // Convert to 0-based index
        stringstream result;

        for (int i = n; i >= 1; --i) {
            factorial /= i;
            int index = k / factorial;
            result << numbers[index];
            numbers.erase(numbers.begin() + index);
            k %= factorial;
        }

        return result.str();
    }
};
