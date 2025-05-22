// Description: Given two words word1 and word2, compute the minimum number of operations 
// (insertions, deletions, replacements) required to convert word1 into word2.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(const string& word1, const string& word2) {
        int n1 = word1.size(), n2 = word2.size();
        // dp[i][j] = min edit distance between word1[0..i) and word2[0..j)
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        
        // converting empty prefix to non-empty: all inserts or deletes
        for (int i = 0; i <= n1; ++i) dp[i][0] = i;
        for (int j = 0; j <= n2; ++j) dp[0][j] = j;
        
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];  // no operation needed
                } else {
                    dp[i][j] = min({
                        dp[i-1][j-1], // replace
                        dp[i-1][j],   // delete
                        dp[i][j-1]    // insert
                    }) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};
