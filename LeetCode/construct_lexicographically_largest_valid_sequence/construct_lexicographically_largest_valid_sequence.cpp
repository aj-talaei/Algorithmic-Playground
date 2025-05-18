// Problem: Construct the Lexicographically Largest Valid Sequence
// Link: https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/
//
// Description:
// Given an integer n, build a sequence `ans` of length 2*n - 1 satisfying:
//  1) The integer 1 occurs exactly once.
//  2) Each integer i in [2..n] occurs exactly twice.
//  3) For every integer i > 1, the two occurrences are exactly i indices apart.
// Return the lexicographically largest such sequence (guaranteed to exist).
//
// Constraints:
//  1 <= n <= 20
//  Sequence length = 2*n - 1 <= 39

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int len = 2 * n - 1;
        vector<int> ans(len, 0);
        vector<bool> used(n + 1, false);
        dfs(0, n, ans, used);
        return ans;
    }

private:
    bool dfs(int pos, int n, vector<int>& ans, vector<bool>& used) {
        int len = ans.size();
        // advance to next empty position
        while (pos < len && ans[pos] != 0) ++pos;
        if (pos == len) return true;  // filled all
        
        // try placing numbers from n down to 1 to maximize lex order
        for (int x = n; x >= 1; --x) {
            if (used[x]) continue;
            if (x == 1) {
                // place single 1
                ans[pos] = 1;
                used[1] = true;
                if (dfs(pos + 1, n, ans, used)) return true;
                ans[pos] = 0;
                used[1] = false;
            } else {
                // need two spots idx and idx+x
                int j = pos + x;
                if (j < len && ans[j] == 0) {
                    ans[pos] = ans[j] = x;
                    used[x] = true;
                    if (dfs(pos + 1, n, ans, used)) return true;
                    ans[pos] = ans[j] = 0;
                    used[x] = false;
                }
            }
        }
        return false;
    }
};
