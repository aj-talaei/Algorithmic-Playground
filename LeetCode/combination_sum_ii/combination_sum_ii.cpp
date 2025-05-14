// Problem: Combination Sum II
// Link: https://leetcode.com/problems/combination-sum-ii/
//
// Description:
// Given a collection of candidate numbers (candidates) and a target number target,
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// The solution set must not contain duplicate combinations and each combination
// must be in non-decreasing order.
//
// Constraints:
// - 1 <= candidates.length <= 30
// - 1 <= candidates[i] <= 200
// - 1 <= target <= 500

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> comb;
        dfs(candidates, target, 0, comb, result);
        return result;
    }

private:
    void dfs(const vector<int>& A,
             int remain,
             int start,
             vector<int>& comb,
             vector<vector<int>>& result)
    {
        if (remain == 0) {
            result.push_back(comb);
            return;
        }
        for (int i = start; i < A.size() && A[i] <= remain; ++i) {
            // Skip duplicates at this level
            if (i > start && A[i] == A[i-1]) continue;
            comb.push_back(A[i]);
            dfs(A, remain - A[i], i + 1, comb, result);
            comb.pop_back();
        }
    }
};
