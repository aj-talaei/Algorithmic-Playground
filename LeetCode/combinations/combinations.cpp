// Problem: Combinations
// Link: https://leetcode.com/problems/combinations/
//
// Description:
// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
// Each combination must be in ascending order, and the solution set must not contain duplicate combinations.
//
// Example:
// Input: n = 4, k = 2
// Output:
// [
//   [1,2],
//   [1,3],
//   [1,4],
//   [2,3],
//   [2,4],
//   [3,4]
// ]
//
// Constraints:
// - 1 <= k <= n <= 20

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(1, n, k, comb, result);
        return result;
    }

private:
    void dfs(int start, int n, int k,
             vector<int>& comb,
             vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(comb);
            return;
        }
        // Prune: only iterate while there are enough numbers left to fill k slots
        for (int i = start; i <= n - k + 1; ++i) {
            comb.push_back(i);
            dfs(i + 1, n, k - 1, comb, result);
            comb.pop_back();
        }
    }
};
