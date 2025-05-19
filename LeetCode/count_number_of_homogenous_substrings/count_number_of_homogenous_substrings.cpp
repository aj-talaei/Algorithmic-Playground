// Problem: Count Number of Homogenous Substrings
// Given a string s, a substring is homogenous if all its characters are the same.
// Return the total number of homogenous substrings of s, modulo 10^9+7.

class Solution {
public:
    int countHomogenous(const string& s) {
        static const int MOD = 1'000'000'007;
        long long result = 0;
        long long runLen = 0;
        char prev = 0;
        
        for (char c : s) {
            if (c == prev) {
                ++runLen;
            } else {
                // add substrings from the previous run: runLen*(runLen+1)/2
                result = (result + runLen * (runLen + 1) / 2) % MOD;
                prev = c;
                runLen = 1;
            }
        }
        // add the final run
        result = (result + runLen * (runLen + 1) / 2) % MOD;
        
        return int(result);
    }
};
