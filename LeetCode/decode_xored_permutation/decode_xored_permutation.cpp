// Source: https://leetcode.com/problems/decode-xored-permutation/
// Description: Given an array `encoded` of length n-1 where encoded[i] = perm[i] XOR perm[i+1]
// for an unknown permutation `perm` of the first n positive integers (n odd), recover `perm`.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(const vector<int>& encoded) {
        int n = encoded.size() + 1;  
        // Compute total XOR of 1^2^...^n
        // For odd n: if ((n+1)/2) is odd, total = 1; otherwise total = 0.
        int total = ((encoded.size() / 2 + 1) % 2);
        // Compute XOR of perm[2] ^ perm[3] ^ ... ^ perm[n]
        int suffixXor = 0;
        for (int i = 1; i < encoded.size(); i += 2) {
            suffixXor ^= encoded[i];
        }
        vector<int> perm(n);
        perm[0] = total ^ suffixXor;  // perm[1] = total ^ (perm[2]^...^perm[n])
        // Recover the rest: perm[i] = perm[i-1] ^ encoded[i-1]
        for (int i = 1; i < n; ++i) {
            perm[i] = perm[i-1] ^ encoded[i-1];
        }
        return perm;
    }
};
