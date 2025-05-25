// Source: https://leetcode.com/problems/gray-code/
// Description: Given a non-negative integer n, generate a Gray code sequence of length 2^n
//              such that successive values differ by exactly one bit. The sequence must begin with 0.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        int total = 1 << n;
        vector<int> result;
        result.reserve(total);
        for (int i = 0; i < total; ++i) {
            // Gray code formula: reflect binary number by its right-shifted self
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};

