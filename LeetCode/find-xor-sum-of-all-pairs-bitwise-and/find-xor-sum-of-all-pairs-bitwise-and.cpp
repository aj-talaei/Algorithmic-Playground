// Source: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Description: Given two non-negative integer arrays `arr1` and `arr2`, consider all bitwise-AND
//              results between every pair `(i, j)` where `i` is an index in `arr1` and `j` in `arr2`.
//              Return the XOR of all those results. It can be shown that this equals
//              (XOR of all elements in `arr1`) & (XOR of all elements in `arr2`).

#include <vector>

using namespace std;

class Solution {
public:
    int getXORSum(const vector<int>& arr1, const vector<int>& arr2) {
        int xor1 = 0;
        for (int v : arr1) {
            xor1 ^= v;
        }
        int xor2 = 0;
        for (int v : arr2) {
            xor2 ^= v;
        }
        return xor1 & xor2;
    }
};

