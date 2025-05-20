// Source: https://leetcode.com/problems/counting-bits/
// Description: Given a non-negative integer num, compute for every i in [0..num] the number of 1's 
//              in the binary representation of i, in O(n) time and O(n) space.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> bits_cnt(num + 1, 0);
        for (int i = 1; i <= num; ++i) {
            // Remove the lowest set bit and add 1
            bits_cnt[i] = bits_cnt[i & (i - 1)] + 1;
        }
        return bits_cnt;
    }
};
