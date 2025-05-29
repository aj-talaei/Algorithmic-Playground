// Source : https://leetcode.com/problems/lexicographical-numbers/

/*
 * Given an integer n, return the numbers from 1 to n in lexicographical order.
 * Example: Input: 13 → Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
 * Optimized to run in O(n) time and minimal extra space.
 */

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int curr = 1;
        for (int i = 0; i < n; ++i) {
            result.push_back(curr);
            if (curr * 10 <= n) {
                curr *= 10;
            } else {
                if (curr >= n) curr /= 10;
                ++curr;
                while (curr % 10 == 0) curr /= 10;
            }
        }
        return result;
    }
};
