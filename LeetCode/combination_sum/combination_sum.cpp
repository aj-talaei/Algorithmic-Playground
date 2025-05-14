// Problem: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
//
// Given an array of distinct positive integers `candidates` and a positive integer `target`,
// return a list of all unique combinations of `candidates` where the chosen numbers sum to `target`.
// You may use the same number from `candidates` unlimited times.
// Combinations must be in non-decreasing order and the solution set must not contain duplicate combinations.
//
// Constraints:
// - 1 <= candidates.length <= 30
// - 1 <= candidates[i] <= 200
// - All elements of candidates are distinct.
// - 1 <= target <= 500

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combination;
        dfs(candidates, target, 0, combination, result);
        return result;
    }

private:
    void dfs(const vector<int>& candidates,
             int remain,
             int start,
             vector<int>& combination,
             vector<vector<int>>& result) {
        if (remain == 0) {
            result.push_back(combination);
            return;
        }
        for (int i = start; i < candidates.size() && candidates[i] <= remain; ++i) {
            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            combination.push_back(candidates[i]);
            dfs(candidates, remain - candidates[i], i, combination, result);
            combination.pop_back();
        }
    }
};
