// Problem: https://leetcode.com/problems/h-index-ii/
// Given a sorted (ascending) array of citation counts, compute the researcher's h-index.
// The h-index is defined as the maximum value `h` such that the researcher has at least
// `h` papers with at least `h` citations each. The goal is to optimize the solution
// using the sorted property of the input (O(log N) time).

#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int h = n - mid;

            if (citations[mid] == h) {
                return h;
            } else if (citations[mid] < h) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return n - low;
    }
};
