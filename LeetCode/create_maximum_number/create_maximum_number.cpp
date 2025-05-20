// Source: https://leetcode.com/problems/create-maximum-number/
// Description: Given two arrays of digits, pick k digits in total (preserving relative order
// within each array) to form the largest possible number.

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i <= k; ++i) {
            if (i > n1 || k - i > n2) continue;
            auto a = pickMax(nums1, i);
            auto b = pickMax(nums2, k - i);
            auto merged = mergeMax(a, b);
            if (isGreater(merged, 0, best, 0))
                best = merged;
        }
        return best;
    }

private:
    // Pick the lexicographically largest subsequence of length k
    vector<int> pickMax(const vector<int>& nums, int k) {
        int drop = nums.size() - k;
        vector<int> stk;
        for (int x : nums) {
            while (drop > 0 && !stk.empty() && stk.back() < x) {
                stk.pop_back();
                --drop;
            }
            stk.push_back(x);
        }
        stk.resize(k);
        return stk;
    }

    // Merge two sequences into the largest possible sequence
    vector<int> mergeMax(const vector<int>& a, const vector<int>& b) {
        vector<int> ans;
        int i = 0, j = 0, n = a.size(), m = b.size();
        while (i < n || j < m) {
            if (isGreater(a, i, b, j))
                ans.push_back(a[i++]);
            else
                ans.push_back(b[j++]);
        }
        return ans;
    }

    // Compare a[i:] vs b[j:] lexicographically
    bool isGreater(const vector<int>& a, int i, const vector<int>& b, int j) {
        int n = a.size(), m = b.size();
        while (i < n && j < m && a[i] == b[j]) {
            ++i; ++j;
        }
        return j == m || (i < n && a[i] > b[j]);
    }
};
