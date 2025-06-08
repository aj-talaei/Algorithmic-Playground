// Source : https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        constexpr int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1; // Initial even count is 1 (empty subarray sum = 0)
        int sum = 0;
        long long result = 0;

        for (int num : arr) {
            sum = (sum + num) % 2;
            if (sum == 0) {
                result += oddCount;
                ++evenCount;
            } else {
                result += evenCount;
                ++oddCount;
            }
        }

        return result % MOD;
    }
};
