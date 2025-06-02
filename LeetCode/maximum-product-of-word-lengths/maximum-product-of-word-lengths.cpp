// Source: https://leetcode.com/problems/maximum-product-of-word-lengths/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> maskToMaxLen;

        for (const string& word : words) {
            int mask = 0;
            for (char c : word) {
                mask |= 1 << (c - 'a');
            }
            maskToMaxLen[mask] = max(maskToMaxLen[mask], (int)word.size());
        }

        int maxProduct = 0;
        for (auto& [mask1, len1] : maskToMaxLen) {
            for (auto& [mask2, len2] : maskToMaxLen) {
                if ((mask1 & mask2) == 0) {
                    maxProduct = max(maxProduct, len1 * len2);
                }
            }
        }

        return maxProduct;
    }
};
