// Problem: https://leetcode.com/problems/h-index/
// Given an array of citation counts for a researcher’s papers, 
// compute the researcher's h-index. The h-index is defined as the maximum value `h` 
// such that the researcher has at least `h` papers with at least `h` citations each.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            int h = n - i;
            if (citations[i] >= h) {
                return h;
            }
        }
        return 0;
    }
};
