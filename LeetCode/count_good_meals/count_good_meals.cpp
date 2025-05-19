
// Problem: Count Good Meals
// A “good meal” consists of two distinct items whose deliciousness values sum to a power of two.
// Given an array `deliciousness`, count the number of good meals (pairs of indices i < j) modulo 10^9 + 7.

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1'000'000'007;
        const int MAX_SUM = 1 << 21;  // since max deliciousness ≤ 2^20, sums up to 2^21
        long long result = 0;
        unordered_map<int,int> freq;

        for (int d : deliciousness) {
            // For each previously seen value, check if its sum with `d` is a power of two
            for (int power = 1; power < MAX_SUM * 2; power <<= 1) {
                int complement = power - d;
                auto it = freq.find(complement);
                if (it != freq.end()) {
                    result = (result + it->second) % MOD;
                }
            }
            // Record this value for future pairs
            freq[d]++;
        }

        return int(result);
    }
};
