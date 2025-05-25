// Source: https://leetcode.com/problems/frog-jump/
// Description: Given sorted stone positions `stones`, determine if a frog starting at `stones[0]`
//              with an initial jump of 1 can reach the last stone. After a jump of length `k`,
//              the next jump must be `k-1`, `k`, or `k+1` (and >0).

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool canCross(const vector<int>& stones) {
        int n = stones.size();
        // Map stone position -> index
        unordered_map<int,int> idx;
        idx.reserve(n);
        for (int i = 0; i < n; ++i) {
            idx[stones[i]] = i;
        }
        // dp[i] = set of jump lengths that land on stones[i]
        vector<unordered_set<int>> dp(n);
        dp[0].insert(0);
        
        for (int i = 0; i < n; ++i) {
            for (int k : dp[i]) {
                // try jumps of k-1, k, k+1
                for (int jump = k - 1; jump <= k + 1; ++jump) {
                    if (jump <= 0) continue;
                    int nextPos = stones[i] + jump;
                    auto it = idx.find(nextPos);
                    if (it != idx.end()) {
                        dp[it->second].insert(jump);
                    }
                }
            }
        }
        return !dp[n - 1].empty();
    }
};

