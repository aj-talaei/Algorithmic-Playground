// Problem: Combination Sum III
// Link: https://leetcode.com/problems/combination-sum-iii/
//
// Description:
// Find all possible combinations of k numbers that add up to a number n,
// using only numbers from 1 to 9. Each combination must be a unique set of numbers,
// and combinations are returned in ascending order within each set.
//
// Constraints:
// - 2 <= k <= 9
// - 1 <= n <= 60

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> comb;
        dfs(k, n, 1, comb, result);
        return result;
    }

private:
    void dfs(int k, int remain, int start,
             vector<int>& comb,
             vector<vector<int>>& result) {
        if (remain < 0 || comb.size() > k) return;
        if (remain == 0 && comb.size() == k) {
            result.push_back(comb);
            return;
        }
        for (int num = start; num <= 9; ++num) {
            comb.push_back(num);
            dfs(k, remain - num, num + 1, comb, result);
            comb.pop_back();
        }
    }
};
