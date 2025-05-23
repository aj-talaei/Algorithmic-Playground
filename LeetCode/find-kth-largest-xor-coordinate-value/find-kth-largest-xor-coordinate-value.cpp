// Source: https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/
// Description: Compute the XOR prefix for each coordinate in a matrix and return the kᵗʰ largest value.

#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        // rowXor[j] will store the XOR of all elements in column j
        // up through the previous row (i−1).
        vector<int> rowXor(n, 0);
        // Min-heap to keep the top k largest XOR values.
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < m; ++i) {
            int prefix = 0;  // XOR of the current row up to column j
            for (int j = 0; j < n; ++j) {
                prefix ^= matrix[i][j];
                // XOR with the above rows' prefix to get the full (i,j) rectangle XOR
                rowXor[j] ^= prefix;
                int val = rowXor[j];
                minHeap.push(val);
                if ((int)minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
        // The root of the min-heap is the kᵗʰ largest value.
        return minHeap.top();
    }
};
