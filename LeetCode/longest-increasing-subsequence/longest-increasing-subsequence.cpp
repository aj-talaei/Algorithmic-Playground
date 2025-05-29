// Source : https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> subseq;

        for (int num : nums) {
            auto it = std::lower_bound(subseq.begin(), subseq.end(), num);
            if (it == subseq.end())
                subseq.push_back(num);
            else
                *it = num;
        }

        return subseq.size();
    }
};
