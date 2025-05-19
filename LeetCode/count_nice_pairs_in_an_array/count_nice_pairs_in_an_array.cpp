// Problem: Count Nice Pairs in an Array
// You’re given a non-negative integer array nums. Define rev(x) as the integer obtained by reversing the digits of x.
// A pair (i, j) is “nice” if 0 ≤ i < j < nums.size() and
//     nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]).
// Return the number of nice pairs modulo 10^9+7.

class Solution {
private:
    // Reverse the decimal digits of n.
    int rev(int n) {
        int x = 0;
        while (n > 0) {
            x = x * 10 + (n % 10);
            n /= 10;
        }
        return x;
    }

public:
    int countNicePairs(vector<int>& nums) {
        static const int MOD = 1'000'000'007;
        long long result = 0;
        unordered_map<int,int> freq;
        // A pair (i,j) is nice iff nums[i] - rev(nums[i]) == nums[j] - rev(nums[j]).
        for (int n : nums) {
            int key = n - rev(n);
            // Each prior occurrence of the same key forms a nice pair with current index.
            result = (result + freq[key]) % MOD;
            ++freq[key];
        }
        return int(result);
    }
};
