// Problem: Minimum Adjacent Swaps to Reach the Kth Smallest Number
// Source  : https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/

class Solution {
private:
    // Generates the next lexicographical permutation
    void nextPermutation(std::string& num) {
        int i = num.size() - 2;
        while (i >= 0 && num[i] >= num[i + 1]) {
            --i;
        }
        if (i >= 0) {
            int j = num.size() - 1;
            while (num[j] <= num[i]) {
                --j;
            }
            std::swap(num[i], num[j]);
        }
        std::reverse(num.begin() + i + 1, num.end());
    }

public:
    int getMinSwaps(std::string num, int k) {
        std::string target = num;
        while (k--) {
            nextPermutation(target);
        }

        int swaps = 0;
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] == target[i]) continue;

            // Find the matching digit in target to bring to index i
            int j = i + 1;
            while (target[j] != num[i]) ++j;

            // Count swaps and perform shifting
            while (j > i) {
                std::swap(target[j], target[j - 1]);
                --j;
                ++swaps;
            }
        }

        return swaps;
    }
};
