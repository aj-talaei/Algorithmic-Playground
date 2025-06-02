// Source: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        if (A.size() > B.size()) return findMedianSortedArrays(B, A); // Ensure A is smaller

        int m = A.size(), n = B.size();
        int totalLeft = (m + n + 1) / 2;

        int left = 0, right = m;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = totalLeft - i;

            int A_left = (i == 0) ? INT_MIN : A[i - 1];
            int A_right = (i == m) ? INT_MAX : A[i];
            int B_left = (j == 0) ? INT_MIN : B[j - 1];
            int B_right = (j == n) ? INT_MAX : B[j];

            if (A_left <= B_right && B_left <= A_right) {
                if ((m + n) % 2 == 0) {
                    return (max(A_left, B_left) + min(A_right, B_right)) / 2.0;
                } else {
                    return max(A_left, B_left);
                }
            } else if (A_left > B_right) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }

        return 0.0; // Should not reach here
    }
};
